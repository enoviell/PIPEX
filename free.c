/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:37:57 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/10 15:37:58 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void	ft_free(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

void	free_cmd_n_file(t_pipex *pipex)
{
	close(pipex->outfile_fd);
	close(pipex->infile_fd);
	ft_free(pipex->cmd1);
	ft_free(pipex->cmd2);
}
