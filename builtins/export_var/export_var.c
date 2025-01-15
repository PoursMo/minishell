/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:04 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 11:24:52 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**malloc_copy_env(char **environ)
{
	int		count;
	char	**new_var;
	int		i;

	count = 0;
	while (environ[count])
		count++;
	new_var = malloc(sizeof(char *) * count + 1);
	if (!new_var)
		return (NULL); //MALLOC ERROR;
	i = 0;
	while (environ[i])
	{
		new_var[i] = ft_strdup(environ[i]);
		printf("%s\n", new_var[i]);
		if (!new_var[i])
		{
			while (--i >= 0)
				free(new_var[i]);
			return (free(new_var), NULL); // MALLOC ERROR
		}
		i++;
	}
	return (new_var);
}

static void	display_all_env(char **environ)
{
	char	**new_environ;
	int		i;

	new_environ = malloc_copy_env(environ);
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

void	export_var(char	*var_name, char *value, char **environ)
{
	if (!var_name)
		display_all_env(environ);
	(void)value;
}
