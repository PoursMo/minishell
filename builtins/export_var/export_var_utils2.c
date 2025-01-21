/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:44:34 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/01/21 11:29:14 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(char ***new_env)
{
	int	i;

	i = 0;
	while ((*new_env)[i])
	{
		free((*new_env)[i]);
		i++;
	}
}

void	display_all_env(char **environ)
{
	int		i;
	char	**new_environ;

	new_environ = malloc_copy_env(environ);
	if (!new_environ)
		return ; //MALLOC ERROR
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

void	display_all_export(char **environ)
{
	int		i;
	char	**new_environ;
	int		index_to_avoid;

	new_environ = malloc_copy_env(environ);
	if (!new_environ)
		return ; //MALLOC ERROR
	new_environ = env_bubble_sort(new_environ);
	index_to_avoid = find_index(new_environ, "_");
	i = 0;
	while (new_environ[i])
	{
		if (i != index_to_avoid)
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
