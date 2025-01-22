/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:56 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:38 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_sorter(char **args, char ***new_env)
{
	int	count;
	int	i;

	count = 0;
	while (args[count])
		count++;
	if (count == 1)
		return ;
	i = 1;
	while (args[i])
	{
		printf("args[i] %s\n", args[i]);
		remove_var(args[i], new_env);
		i++;
	}
}