/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:33:34 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/09 15:06:39 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "./libft/libft.h"

void	child_process(char **argv, char **envp, int *fd);
void	father_process(char **argv, char **envp, int *fd);
void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

#endif
