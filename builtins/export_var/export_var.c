/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:04 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 10:40:47 by lbaecher         ###   ########.fr       */
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
		return (perror("malloc"), -1);
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

static char	*remove_plus_sign(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != '+')
		i++;
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '+')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	free(*str);
	return (new_str);
}

int	export_var(char *var_name, char *value, char **environ)
{
	if (var_name[ft_strlen(var_name) - 1] == '+')
	{
		var_name = remove_plus_sign(var_name);
		if (!var_name)
			return (perror("malloc:"), 1);
		if (check_existing_var(var_name, environ))
			return (append_env_var(var_name, value, environ));
		else
			return (add_env_var(var_name, value, environ));
	}
	else
	{
		if (check_existing_var(var_name, environ))
			return (replace_env_var(var_name, value, environ));
		else
			return (add_env_var(var_name, value, environ));
	}
}
