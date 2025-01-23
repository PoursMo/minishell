/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_streams.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:46:47 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/23 12:20:39 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_std_streams(int mode)
{
	static int	std_streams[2];

	if (mode == 0)
	{
		std_streams[STDIN_FILENO] = dup(STDIN_FILENO);
		std_streams[STDOUT_FILENO] = dup(STDOUT_FILENO);
		if (std_streams[STDIN_FILENO] == -1 || std_streams[STDOUT_FILENO] == -1)
			return (perror("dup"), -1);
	}
	else if (mode == 1)
	{
		if (dup2(std_streams[STDIN_FILENO], STDIN_FILENO) == -1)
			return (perror("dup2"), -1);
		if (dup2(std_streams[STDOUT_FILENO], STDOUT_FILENO) == -1)
			return (perror("dup2"), -1);
		if (close(std_streams[STDIN_FILENO]) == -1)
			return (perror("close"), -1);
		if (close(std_streams[STDOUT_FILENO]) == -1)
			return (perror("close"), -1);
	}
	return (0);
}

int	reset_std_streams(void)
{
	return (update_std_streams(1));
}

int	save_std_streams(void)
{
	return (update_std_streams(0));
}
