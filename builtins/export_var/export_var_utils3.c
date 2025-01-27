/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:02:49 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/01/27 10:27:10 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exportable(char *var)
{
	int	i;

	i = 0;
	while (var[i] && !(ft_isalpha(var[i])) && var[i] != '=')
		i++;
	if (var[i] == '=' || var[i] == '\0')
		return (0);
	i = 0;
	while (var[i])
	{
		if (var[i] == '+' && (!var[i + 1] || !var[i + 1] == '='))
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
