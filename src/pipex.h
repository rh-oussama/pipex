/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:18:19 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/13 15:33:49 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft_printf_gnl/ft_printf.h"

void	free_split(char **arr);
char	**get_path(char **envp);
char	*get_final_path(char *command, char **envp);
void	handle_child_process(int argc, int *fd_open \
	, int *fd, char ***argv_envp);
void	handle_parent_process(int *fd_open, int *fd);
void	dup2_close(int fd1, int fd2);
void	execute_command(char *path, char **args, char **envp);
char	*read_heredoc(const char *limiter);
int		herdoc_handle(char **argv);
void	ft_error(char *msg, char	*pgname);

#endif