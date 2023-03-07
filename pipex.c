/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:36:26 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/07 16:03:11 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int child_process(int fd[2], char **argv, char **envp)
// {
// 	int		fd_in;
// 	char	*path;

// 	close(fd[0]);
// 	dup2(fd[1], 1);
// 	close(fd[1]);
// 	path = get_path(argv[1], envp);
// 	fd_in = open(argv[1], O_RDONLY);
// 	if (fd_in == -1)
// 		ft_error("Open error");
// 	dup2(fd_in, 0);
// 	close(fd_in);
// 	execve(path, &argv[1], envp);
// 	ft_error("Execve error");
// 	return (0);
// }

void	child_process(char **argv, char **envp, int *fd)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		ft_error("Open error");
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	execute(&argv[2], envp);
}


void	father_process(char **argv, char **envp, int *fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		ft_error("Open error");
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	execute(&argv[3], envp);
}


int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		ft_error("Wrong number of arguments");
	if (pipe(fd) == -1)
		ft_error("Pipe error");
	pid = fork();
	if (pid == -1)
		ft_error("Fork error");
	if (pid == 0)
		child_process(argv, envp, fd);
	else
	{
		waitpid(pid, &status, 0);
		father_process(argv, envp, fd);
	}
	return (0);
}
