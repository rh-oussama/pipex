/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:08:17 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/13 15:57:15 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
input_file fd => fd_open[0];
prev_read_end => fd_open[1];
i start from 2 command => fd_open[2];
proccess id => fd_open[3];
outpou_file fd => fd_open[4];
*/
void	handle_child_process(int argc, int *fd_open, int *fd, char ***argv_envp)
{
	char	**args;
	char	*path;

	args = ft_split(argv_envp[0][fd_open[2]], ' ');
	path = get_final_path(args[0], argv_envp[1]);
	dup2_close(fd_open[1], STDIN_FILENO);
	if (fd_open[2] + 2 < argc)
		dup2_close(fd[1], STDOUT_FILENO);
	if (fd_open[2] == (argc - 2))
		dup2_close(fd_open[4], STDOUT_FILENO);
	close(fd[0]);
	execute_command(path, args, argv_envp[1]);
}

void	handle_parent_process(int *fd_open, int *fd)
{
	close(fd_open[1]);
	close(fd[1]);
	fd_open[1] = fd[0];
}

void message()
{
	write(1, "Invalid Number of arguments!\n", 29);
	exit(EXIT_FAILURE);
}
void	rules_check(int argc, char **argv, int *fd_open)
{
	if (argc <= 5)
		message();
	if (strcmp("here_doc", argv[1]) == 0)
	{
		if (argc != 6)
			message();
		fd_open[0] = herdoc_handle(argv);
		fd_open[2] = 3;
		fd_open[4] = open(argv[argc - 1], O_RDWR | \
						O_CREAT | O_APPEND, 0644);
	}
	else if (strcmp("here_doc", argv[1]) != 0)
	{
		fd_open[2] = 2;
		fd_open[0] = open(argv[1], O_RDONLY);
		fd_open[4] = open(argv[argc - 1], O_RDWR | \
						O_CREAT | O_TRUNC, 0644);
	}
	if (fd_open[0] == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	fd_open[1] = fd_open[0];
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		fd_open[5];
	char	**argv_envp[2];

	argv_envp[0] = argv;
	argv_envp[1] = envp;
	rules_check(argc, argv, fd_open);
	while (fd_open[2] < argc - 1)
	{
		pipe(fd);
		fd_open[3] = fork();
		if (fd_open[3] == 0)
			handle_child_process(argc, fd_open, fd, argv_envp);
		else
			handle_parent_process(fd_open, fd);
		fd_open[2]++;
	}
	while (wait(NULL) != -1)
	{
	}
	return (0);
}
