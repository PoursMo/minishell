/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:04 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 10:37:26 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**malloc_env(char **envp)
{
	int		count;
	char	**env_var;
	int		i;

	count = 0;
	while (envp[count])
		count++;
	env_var = malloc(sizeof(char *) * count);
	if (!env_var)
		return (NULL); //MALLOC ERROR;
	i = 0;
	while (envp[i])
	{
		env_var[i] = ft_strdup(envp[i]);
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

static char	**bubble_sort(char **env_var)
{
	char	*temp;
	int		i;

	i = 0;
	while (env_var[i] && env_var[i + 1])
	{
		if (ft_strncmp(env_var[i], env_var[i + 1], ft_strlen(env_var[i])) > 0)
		{
			temp = env_var[i];
			env_var[i] = env_var[i + 1];
			env_var[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (env_var);
}

static void	display_all_env(char **envp)
{
	char	**env_var;
	int		i;

	env_var = malloc_env(envp);
	if (!env_var)
		return ; //MALLOC ERROR;
	env_var = bubble_sort(env_var);
	i = 0;
	while (env_var[i])
		printf("%s\n", env_var[i++]);
	while (env_var[i])
		free(env_var[i++]);
	free(env_var);
}

void	export_var(char	*str, char **envp)
{
	if (!str)
	{
		display_all_env(envp);
	}
}
