/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:56 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 15:15:22 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_sorter(char **args)
{
	int	count;
	int	i;

	count = 0;
	while (args[count])
		count++;
	if (count == 1)
		return (0);
	i = 1;
	while (args[i])
	{
		if(remove_var(args[i], get_minishell_env()) == -1)
			return (-1);
		i++;
	}
	return (0);
}
