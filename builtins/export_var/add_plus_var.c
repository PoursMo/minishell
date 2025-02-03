/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plus_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:16:40 by lbaecher          #+#    #+#             */
/*   Updated: 2025/02/03 08:44:38 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	new_plus_env_var_empty(char *var, char **new_var)
{
	int	tot_len;
	int	i;

	tot_len = ft_strlen(var) - 1;
	(*new_var) = malloc(sizeof(char) * (tot_len + 1));
	if (!(*new_var))
		return (perror("malloc"), -1);
	i = 0;
	while (var[i] && var[i] != '+')
	{
		(*new_var)[i] = var[i];
		i++;
	}
	(*new_var)[i] = '\0';
	return (0);
}

static char	*fill_new_plus_env_str(char *new_var, char *var, char *val)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (var[i] && var[i] != '+')
		new_var[c++] = var[i++];
	i = 0;
	new_var[c++] = '=';
	while (val[i])
		new_var[c++] = val[i++];
	new_var[c] = '\0';
	return (new_var);
}

static int	new_plus_env_var_str(char *var, char *val, char **new_var)
{
	int	tot_len;

	tot_len = ft_strlen(var) - 1 + ft_strlen(val);
	(*new_var) = malloc(sizeof(char) * (tot_len + 2));
	if (!new_var)
		return (perror("malloc"), -1);
	*new_var = fill_new_plus_env_str(*new_var, var, val);
	return (0);
}

int	add_plus_env_var(char *var, char *val, char **environ)
{
	char	**new_env;
	char	*new_var;
	int		index;

	index = 0;
	new_env = malloc_add_var(environ, &index);
	if (new_env == NULL)
		return (1);
	if (val)
	{
		if (new_plus_env_var_str(var, val, &new_var) == -1)
			return (free_env(new_env), 1);
	}
	else
	{
		if (new_plus_env_var_empty(var, &new_var) == -1)
			return (free_env(new_env), 1);
	}
	new_env[index] = new_var;
	new_env[index + 1] = NULL;
	free_env(environ);
	set_minishell_env(new_env);
	free(environ);
	return (0);
}
