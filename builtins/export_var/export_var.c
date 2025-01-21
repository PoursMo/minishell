/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:04 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/21 09:46:00 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_all_env(char **environ)
{
	int		i;
	char	**new_environ;

	new_environ = malloc_copy_env(environ);
	if (!new_environ)
		return ; //MALLOC ERROR
	new_environ = env_bubble_sort(new_environ);
	i = 0;
	while (new_environ[i])
	{
		printf("%s\n", new_environ[i]);
		i++;
	}
	i = 0;
	while (new_environ[i])
	{
		free(new_environ[i]);
		i++;
	}
	free(new_environ);
}

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

static void	replace_env_var(char *var_name, char *val, char ***environ)
{
	int		i;
	char	*new_var;

	i = 0;
	while ((*environ)[i])
	{
		if (is_same_env_var(var_name, (*environ)[i]))
			break ;
		else
			i++;
	}
	new_var = malloc(sizeof(char) * (ft_strlen(var_name) + ft_strlen(val) + 2));
	if (!new_var)
		return ; //MALLOC ERROR
	new_var = fill_env_str(new_var, var_name, val);
	free((*environ)[i]);
	(*environ)[i] = new_var;
}

static void	add_env_var(char *var, char *val, char ***environ)
{
	char	**new_env;
	char	*new_var;
	int		index;
	int		tot_len;

	index = 0;
	new_env = malloc_add_var(*environ, &index);
	tot_len = ft_strlen(var) + ft_strlen(val);
	new_var = malloc(sizeof(char) * (tot_len + 2));
	if (!new_var)
		return ; //MALLOC ERROR
	new_var = fill_env_str(new_var, var, val);

	new_env[index] = new_var;
	new_env[index + 1] = NULL;
	free_env(environ);
	free(*environ);
	*environ = new_env;
}

void	export_var(char *var_name, char *value, char ***environ)
{
	if (check_existing_var(var_name, *environ))
		replace_env_var(var_name, value, environ);
	else
		add_env_var(var_name, value, environ);
}
