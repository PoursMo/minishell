/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:04 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 12:53:44 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display_all_env(char **envp)
{
	char	**new_environ;
	int		i;

	new_environ = malloc_copy_env(envp);
	if (!new_environ)
		return ; //MALLOC ERROR;
	new_environ = env_bubble_sort(new_environ);
	i = 0;
	while (new_environ[i])
		printf("%s\n", new_environ[i++]);
	while (new_environ[i])
		free(new_environ[i++]);
	free(new_environ);
}

static int	check_existing_var(char *var_name, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (is_same_env_var(var_name, envp[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	replace_env_var(char *var_name, char *val, char **envp)
{
	int		i;
	char	*new_var;

	i = 0;
	while (envp[i])
	{
		if (is_same_env_var(var_name, envp[i]))
			break ;
		else
			i++;
	}
	new_var = malloc(sizeof(char) * (ft_strlen(var_name) + ft_strlen(val) + 2));
	if (!new_var)
		return ; //MALLOC ERROR
	new_var = fill_env_str(new_var, var_name, val);
	envp[i] = new_var;
}

// void	add_env_var(char)

void	export_var(char *var_name, char *value, char **envp)
{
	if (!var_name)
		display_all_env(envp);
	else
	{
		if (check_existing_var(var_name, envp))
			replace_env_var(var_name, value, envp);
		// else
		// 	add_env_var(var_name, value, environ);
	}
	(void)value;
}
