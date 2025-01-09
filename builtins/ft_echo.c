/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:17 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/09 16:48:10 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_echo_append(int fd_out, int new_line_flag, char *str)
{
	int	check;

	if (read(fd, 0, 0) == -1)
	{
		//ADD ERROR MESSAGE
		//EXIT GO TO NEW LINE
	}
	while (check != 0)
		check = read(fd, NULL, 1)
	write(fd_out, &str, ft_strlen(str));
}

static void	ft_echo_replace(int fd_out, char *str)
{

}

void	ft_echo(int fd_out, int new_line_flag, int append, char *str)
{
	if (fd_out == 1)
	{
		if (opt == 'n')
			printf("%s\n", str);
		else
			printf("%s", str);
	}
	else
	{
		if(append == 1)
			ft_echo_append();
		else
			ft_echo_replace();
	}
}