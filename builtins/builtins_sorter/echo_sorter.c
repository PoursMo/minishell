/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:39:48 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 14:40:01 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_sorter(char **args)
{
	int	count;

	count = 1;
	if (ft_strlen(args[1]) == 2 && !(ft_strncmp(args[1], "-n", 2)))
	{
		count++;
		while (args[count + 1] != NULL)
		{
			ft_echo(0, args[count]);
			printf(" ");
			count++;
		}
		ft_echo(0, args[count]);
	}
	else
	{
		while (args[count + 1])
		{
			ft_echo(0, args[count++]);
			printf(" ");
		}
		ft_echo(1, args[count]);
	}
	return (0);
}
