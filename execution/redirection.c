/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:46:38 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/15 14:50:56 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void setup_input_redirection(const char *file)
{
	int fd;

	if(access(file, R_OK) == -1)
	{
		perror(file);
		fd = open("/dev/null", O_RDONLY);
		if(fd == -1)
		{
			perror(file);
			return ;
		}
	}
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			return ;
		}
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("dup2");
	if(close(fd) == -1)
		perror("close");
}
void setup_output_redirection(const char *file, int mode)
{
	int fd;

	if(!mode)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if(fd == -1)
	{
		perror(file);
		return ;
	}
	if(dup2(fd, STDOUT_FILENO) == -1)
		perror("dup2");
	if(close(fd) == -1)
		perror("close");
}


// THIS ONE CAN BE IMPROVED
void setup_heredoc(char *doc)
{
	char *line;
	int pipe_fds[2];

	if(pipe(pipe_fds) == -1)
	{
		perror("pipe");
		return ;
	}
	line = get_next_line(STDIN_FILENO);
	while(line)
	{
		if(!ft_strncmp(line, doc, get_biggest(ft_strlen(line) - 1, ft_strlen(doc))))
		{
			free(line);
			break ;
		}
		write(pipe_fds[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if(close(pipe_fds[1]) == -1)
		perror("close");
	if(dup2(pipe_fds[0], STDIN_FILENO) == -1)
		perror("dup2");
	if(close(pipe_fds[0]) == -1)
		perror("close");
}
