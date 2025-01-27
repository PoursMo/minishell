/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:39:48 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 09:21:01 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_n(char *str)
{
	int	i;

	i = 1;
	while (str[i] == 'n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

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
	if (!(ft_strncmp(args[1], "-n", 2)) && only_n(args[1]))
	{
		i = 2;
		while (!(ft_strncmp(args[i], "-n", 2)))
			i++;
		while (args[i + 1])
			ft_echo(0, args[i++], 0);
		ft_echo(0, args[i], 1);
	}
	else
	{
		i = 1;
		while (args[i + 1])
			ft_echo(0, args[i++], 0);
		ft_echo(1, args[i], 1);
	}
	return (1);
}
