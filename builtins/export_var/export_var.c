/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:04 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 14:41:09 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_existing_var(char *var_name, char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (is_same_env_var(var_name, environ[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	replace_env_var(char *var_name, char *val, char **environ)
{
	int		i;
	char	*new_var;

	i = 0;
	while (environ[i])
	{
		if (is_same_env_var(var_name, environ[i]))
			break ;
		else
			i++;
	}
	if (!val)
		return (0);
	new_var = malloc(sizeof(char) * (ft_strlen(var_name) + ft_strlen(val) + 2));
	if (!new_var)
		return (perror("Malloc"), -1);
	new_var = fill_env_str(new_var, var_name, val);
	free(environ[i]);
	environ[i] = new_var;
	set_minishell_env(environ);
	return (0);
}

static int	add_env_var(char *var, char *val, char **environ)
{
	char	**new_env;
	char	*new_var;
	int		index;

	index = 0;
	new_env = malloc_add_var(environ, &index);
	if (new_env == NULL)
		return (-1);
	if (val)
	{
		if (new_env_var_str(var, val, &new_var) == -1)
			return (free_env(new_env), -1);
	}
	else
	{
		if (new_env_var_empty(var, &new_var) == -1)
			return (free_env(new_env), -1);
	}
	new_env[index] = new_var;
	new_env[index + 1] = NULL;
	free_env(environ);
	set_minishell_env(new_env);
	free(environ);
	return (0);
}

int	export_var(char *var_name, char *value, char **environ)
{
	if (check_existing_var(var_name, environ))
	{
		return (replace_env_var(var_name, value, environ));
	}
	else
		return (add_env_var(var_name, value, environ));
}
