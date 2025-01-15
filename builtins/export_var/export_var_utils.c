/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:06:40 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 11:25:00 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_bubble_sort(char **new_env)
{
	char	*temp;
	int		i;

	i = 0;
	while (new_env[i] && new_env[i + 1])
	{
		if (ft_strncmp(new_env[i], new_env[i + 1], ft_strlen(new_env[i])) > 0)
		{
			temp = new_env[i];
			new_env[i] = new_env[i + 1];
			new_env[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (new_env);
}