/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:28:49 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 16:29:43 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	write_heredoc_lines(int write_fd, char *doc)
{
	char	*line;

	while (1)
	{
		write(get_std_streams()[1], "> ", 2);
		line = get_next_line(get_std_streams()[0]);
		if (!line)
			break ;
		if (!ft_strncmp(line, doc, msmax(ft_strlen(line) - 1, ft_strlen(doc))))
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		free(line);
	}
	return (0);
}

int	setup_heredoc(char *doc)
{
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		return (perror("pipe"), -1);
	set_signals('h');
	if (write_heredoc_lines(pipe_fds[1], doc) == -1)
		return (-1);
	if (close(pipe_fds[1]) == -1)
		return (perror("close"), -1);
	if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
		return (perror("dup2"), -1);
	if (close(pipe_fds[0]) == -1)
		return (perror("close"), -1);
	return (0);
}
