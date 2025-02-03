/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:02:49 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/02/03 08:45:06 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exportable(char *var)
{
	int	i;

	i = 0;
	if (var[i] != '_' && !(var[i] >= 'a' && var[i] <= 'z')
		&& !(var[i] >= 'A' && var[i] <= 'Z'))
		return (0);
	i++;
	while (var[i] && var[i] != '=' && var[i] != '+')
	{
		if (!(ft_isalnum(var[i])))
			return (0);
		i++;
	}
	return (1);
}

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
		return (perror("malloc"), -1);
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
		return (perror("malloc"), -1);
	i = 0;
	while (var[i])
	{
		(*new_var)[i] = var[i];
		i++;
	}
	(*new_var)[i] = '\0';
	return (0);
}
