/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:17:53 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/28 14:26:30 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_small_env(void)
{
	char	**new_env;

	new_env = malloc(sizeof(char *) * 1);
	if (!new_env)
		return (perror("malloc"), -1);
	new_env[0] = NULL;
	set_minishell_env(new_env);
	if (export_var("PWD", getcwd(NULL, 0), get_minishell_env()))
		return (-1);
	if (export_var("OLDPWD", "", get_minishell_env()))
		return (-1);
	if (export_var("SHLVL", "0", get_minishell_env()))
		return (-1);
	return (0);
}

char	**create_new_env(char **old_env)
{
	char	**new_env;

	new_env = malloc_copy_env(old_env);
	if (!new_env)
		return (perror("malloc"), NULL);
	return (new_env);
}
