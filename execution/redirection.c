/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:46:38 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/22 16:23:31 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setup_input_redirection(const char *file)
{
	int	fd;

	if (access(file, R_OK) == -1)
	{
		perror(file);
		fd = open("/dev/null", O_RDONLY); // ?
		if (fd == -1)
			return (perror(file), -1);
	}
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			return (perror("open"), -1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		return (perror("dup2"), -1);
	if (close(fd) == -1)
		return (perror("close"), -1);
	return (0);
}

static int	setup_output_redirection(const char *file, int mode)
{
	int	fd;

	if (!mode)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (perror(file), -1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (perror("dup2"), -1);
	if (close(fd) == -1)
		return (perror("close"), -1);
	return (0);
}

static int	setup_heredoc(char *doc)
{
	char	*line;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		return (perror("pipe"), -1);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if(!line)
			break ;
		if (!ft_strncmp(line, doc, get_biggest(ft_strlen(line) - 1, ft_strlen(doc))))
		{
			free(line);
			break ;
		}
		write(pipe_fds[1], line, ft_strlen(line));
		free(line);
	}
	if (close(pipe_fds[1]) == -1)
		return (perror("close"), -1);
	if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
		return (perror("dup2"), -1);
	if (close(pipe_fds[0]) == -1)
		return (perror("close"), -1);
	return (0);
}

int	setup_redirections(t_list *start, t_list *end)
{
	while (start != end)
	{
		if (is_operator_not_pipe(*(char *)start->content))
		{
			remove_quotes(start->next->content);
			if (!ft_strncmp(start->content, ">>", 2))
			{
				if(setup_output_redirection(start->next->content, 1) == -1)
					return (-1);
			}
			else if (!ft_strncmp(start->content, ">", 1))
			{
				if(setup_output_redirection(start->next->content, 0) == -1)
					return (-1);
			}
			else if (!ft_strncmp(start->content, "<<", 2))
			{
				if(setup_heredoc(start->next->content) == -1)
					return (-1);
			}
			else if (!ft_strncmp(start->content, "<", 1))
			{
				if(setup_input_redirection(start->next->content) == -1)
					return (-1);
			}
		}
		start = start->next;
	}
	return (0);
}
