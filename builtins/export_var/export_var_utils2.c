/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:44:34 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/01/22 14:54:11 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(char **new_env)
{
	int	i;

	i = 0;
	while (new_env[i])
	{
		free(new_env[i]);
		i++;
	}
}

void	display_all_env(char **environ)
{
	int		i;
	char	**new_environ;

	new_environ = malloc_copy_env(environ);
	if (!new_environ)
		return ;
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

void	special_print(char *line)
{
	int	i;

	i = 0;
	printf("declare -x ");
	while (line[i] != '=')
		printf("%c", line[i++]);
	i++;
	printf("%s", "=\"");
	while (line[i] != '\0')
		printf("%c", line[i++]);
	printf("%s", "\"\n");
}

void	display_all_export(char **environ)
{
	int		i;
	char	**new_environ;
	int		index_to_avoid;

	new_environ = malloc_copy_env(environ);
	if (!new_environ)
		return ;
	new_environ = env_bubble_sort(new_environ);
	index_to_avoid = find_env_index(new_environ, "_");
	i = 0;
	while (new_environ[i])
	{
		if (i != index_to_avoid)
			special_print(new_environ[i]);
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
