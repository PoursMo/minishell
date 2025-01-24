/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:02:28 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/15 14:19:34 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strnjoin(char *s1, char *s2, size_t s2n)
{
	char	*new;
	size_t	size;
	size_t	s1len;
	size_t	s2len;

	if ((!s1 && !s2) || !s2 || !*s2)
		return (NULL);
	s1len = 0;
	if (s1)
		s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s2n > s2len)
		s2n = s2len;
	size = s1len + s2n + 1;
	new = ft_calloc(sizeof(char), size);
	if (!new)
		return (perror("get_next_line"), free(s1), NULL);
	if (s1)
		ft_strlcat(new, s1, size);
	ft_strlcat(new, s2, size);
	free(s1);
	return (new);
}

static char	*get_line(t_buffer *buff, char **new, size_t offset)
{
	char	*newline_ptr;
	size_t	linelen;

	newline_ptr = ft_memchr(buff->buffer + offset, '\n',
			ft_strlen(buff->buffer + offset) + 1);
	if (newline_ptr)
	{
		linelen = newline_ptr + 1 - (buff->buffer + offset);
		*new = strnjoin(*new, buff->buffer + offset, linelen);
		buff->offset = offset + linelen;
		return (*new);
	}
	return (NULL);
}

static ssize_t	read_and_process(int fd, t_buffer *buff, char **new)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buff->buffer, GNL_BUFF_SIZE);
	if (bytes_read == -1)
	{
		buff->offset = 0;
		free(*new);
		return (-1);
	}
	if (bytes_read == 0)
	{
		buff->offset = 0;
		return (0);
	}
	if (bytes_read < GNL_BUFF_SIZE)
		buff->buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffers[GNL_MAX_FD];
	char			*new;
	ssize_t			bytes_read;

	if (GNL_BUFF_SIZE < 1 || fd < 0 || fd >= GNL_MAX_FD)
		return (NULL);
	new = NULL;
	if (buffers[fd].offset > 0 && GNL_BUFF_SIZE > 1)
	{
		if (get_line(&buffers[fd], &new, buffers[fd].offset))
			return (new);
		new = strnjoin(new, buffers[fd].buffer + buffers[fd].offset,
				GNL_BUFF_SIZE - buffers[fd].offset);
	}
	while (1)
	{
		bytes_read = read_and_process(fd, &buffers[fd], &new);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			return (new);
		if (get_line(&buffers[fd], &new, 0))
			return (new);
		new = strnjoin(new, buffers[fd].buffer, bytes_read);
	}
}