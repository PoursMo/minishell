/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:02:49 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/01/23 14:36:36 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_env_str_empty(char *line, char **name_str)
{
	int	i;

	i = 0;
	while (line[i])
	{
		(*name_str)[i] = line[i];
		i++;
	}
	(*name_str)[i] = '\0';
}

int	new_env_var_str(char *var, char *val, char **new_var)
{
	int	tot_len;

	tot_len = ft_strlen(var) + ft_strlen(val);
	(*new_var) = malloc(sizeof(char) * (tot_len + 2));
	if (!new_var)
		return (perror("Malloc"), -1);
	*new_var = fill_env_str(*new_var, var, val);
	return (0);
}

int	new_env_var_empty(char *var, char **new_var)
{
	int	tot_len;
	int	i;

	tot_len = ft_strlen(var);
	(*new_var) = malloc(sizeof(char) * (tot_len + 1));
	if (!(*new_var))
		return (perror("Malloc"), -1);
	i = 0;
	while (var[i])
	{
		(*new_var)[i] = var[i];
		i++;
	}
	(*new_var)[i] = '\0';
	return (0);
}
