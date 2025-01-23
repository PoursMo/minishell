/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:34:58 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 15:52:14 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*my_get_env(char *var_name)
{
	int		index;
	char	*return_var;
	char	**env;

	env = get_minishell_env();
	index = find_env_index(env, var_name);
	if (index == -1)
		return (NULL);
	else
	{
		return_var = env[index];
		while (*return_var != '=' && return_var)
			return_var++;
		if (*return_var == '=')
			return_var++;
	}
	return (return_var);
}
