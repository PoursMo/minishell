/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:39:48 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 09:19:20 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_sorter(char **args)
{
	int	count;

	count = 0;
	if (ft_strlen(args[1]) == 2 && !(ft_strncmp(args[1], "-n", 2)))
	{
		while (args[count + 1])
			ft_echo(0, args[count++]);
		ft_echo(1, args[count]);
	}
	else
	{
		while (args[count])
			ft_echo(0, args[count++]);
	}
	return (0);
}
