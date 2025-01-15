/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:06:40 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 11:07:31 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_bubble_sort(char **env_var)
{
	char	*temp;
	int		i;

	i = 0;
	while (env_var[i] && env_var[i + 1])
	{
		if (ft_strncmp(env_var[i], env_var[i + 1], ft_strlen(env_var[i])) > 0)
		{
			temp = env_var[i];
			env_var[i] = env_var[i + 1];
			env_var[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (env_var);
}