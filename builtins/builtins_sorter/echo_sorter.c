/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:39:48 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 13:44:03 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	echo_counter(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	echo_sorter(char **args)
{
	int	i;

	if (echo_counter(args) == 1)
		return (printf("\n"), 0);
	if (ft_strlen(args[1]) == 2 && !(ft_strncmp(args[1], "-n", 2)))
	{
		i = 2;
		while (args[i])
		{
			ft_echo(0, args[i++]);
			if (args[i])
				printf(" ");
		}
	}
	else
	{
		i = 1;
		while (args[i + 1])
		{
			ft_echo(0, args[i++]);
			printf(" ");
		}
		ft_echo(1, args[i]);
	}
	return (1);
}
