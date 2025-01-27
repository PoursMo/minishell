/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:46:38 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 16:29:24 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setup_input_redirection(const char *file)
{
	int	fd;

	if (access(file, R_OK) == -1)
	{
		perror(file);
		fd = open("/dev/null", O_RDONLY);
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

static int	handle_redirection(t_list *token)
{
	remove_quotes(token->next->content);
	if (!ft_strncmp(token->content, ">>", 2))
	{
		if (setup_output_redirection(token->next->content, 1) == -1)
			return (-1);
	}
	else if (!ft_strncmp(token->content, ">", 1))
	{
		if (setup_output_redirection(token->next->content, 0) == -1)
			return (-1);
	}
	else if (!ft_strncmp(token->content, "<<", 2))
	{
		if (setup_heredoc(token->next->content) == -1)
			return (-1);
	}
	else if (!ft_strncmp(token->content, "<", 1))
	{
		if (setup_input_redirection(token->next->content) == -1)
			return (-1);
	}
	return (0);
}

int	setup_redirections(t_list *start, t_list *end)
{
	while (start != end)
	{
		if (is_operator_not_pipe(*(char *)start->content))
		{
			if (handle_redirection(start) == -1)
				return (-1);
		}
		start = start->next;
	}
	return (0);
}
