/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:04 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 11:10:35 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**malloc_env(char **environ)
{
	int		count;
	char	**env_var;
	int		i;

	count = 0;
	while (environ[count])
		count++;
	env_var = malloc(sizeof(char *) * count);
	if (!env_var)
		return (NULL); //MALLOC ERROR;
	i = 0;
	while (environ[i])
	{
		env_var[i] = ft_strdup(environ[i]);
		if (!env_var[i])
		{
			while (--i >= 0)
				free(env_var[i]);
			return (free(env_var), NULL); // MALLOC ERROR
		}
		i++;
	}
	return (env_var);
}

static void	display_all_env(char **environ)
{
	char	**new_environ;
	int		i;

	new_environ = malloc_env(environ);
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

void	export_var(char	*str, char *value, char **environ)
{
	if (!str)
		display_all_env(environ);
	(void)value;
}
