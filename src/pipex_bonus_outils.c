/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_outils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:20:14 by orhaddao          #+#    #+#             */
/*   Updated: 2024/01/13 15:34:51 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*read_heredoc(const char *limiter)
{
	char	*tmp;
	char	*buffer;
	char	*new_buffer;

	write(1, "heredoc > ", 10);
	buffer = NULL;
	tmp = get_next_line(0);
	while (tmp != NULL)
	{
		if (strcmp(tmp, limiter) == 0)
		{
			free(tmp);
			break ;
		}
		new_buffer = ft_strjoin(buffer, tmp);
		free(buffer);
		buffer = new_buffer;
		free(tmp);
		write(1, "heredoc > ", 10);
		tmp = get_next_line(0);
	}
	get_next_line(INT_MAX);
	return (buffer);
}

int	herdoc_handle(char **argv)
{
	char	*limiter;
	char	*buffer;
	int		pi[2];

	limiter = ft_strjoin(argv[2], "\n");
	buffer = read_heredoc(limiter);
	pipe(pi);
	write(pi[1], buffer, ft_strlen(buffer));
	close(pi[1]);
	free(buffer);
	free(limiter);
	return (pi[0]);
}
