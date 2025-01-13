/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:42:38 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/13 09:55:44 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes.h"

int	*create_pipe(int read_ext, int write_ext)
{
	int	*new_pipe;

	if (!(read_ext >= 0 && write_ext >= 0))
		return (NULL);//Error, wrong file descriptor
	if (!(read_ext <= 1024 && write_ext <= 1024))
		return (NULL); //Error, wrong file descriptor
	new_pipe = malloc(sizeof(int) * 2);
	new_pipe[0] = read_ext;
	new_pipe[1] = write_ext;
	if (pipe(new_pipe) == 1)
		return (NULL); //Error when creating the pipe
	return (new_pipe);
}
