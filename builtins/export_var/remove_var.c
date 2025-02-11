/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:07:13 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/02/03 10:51:49 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_index(char **envp, char *var_name)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, ft_strlen(var_name)) == 0)
			if (envp[i][ft_strlen(var_name)] == '='
				|| envp[i][ft_strlen(var_name)] == '\0')
				return (i);
		i++;
	}
	return (-1);
}

int	malloc_loop(char **envp, int n_i, char ***new_var)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (envp[y])
	{
		if (y == n_i)
			y++;
		else
		{
			(*new_var)[i] = ft_strdup(envp[y]);
			if (!((*new_var)[i]))
			{
				while (--i >= 0)
					free((*new_var)[i--]);
				return (free((*new_var)), perror("malloc"), -1);
			}
			i++;
			y++;
		}
	}
	return (i);
}

char	**malloc_copy_less(char **envp, int not_included)
{
	int		i;
	int		last_index;
	char	**new_var;

	last_index = 0;
	while (envp[last_index])
		last_index++;
	new_var = malloc(sizeof(char *) * (last_index));
	if (!new_var)
		return (perror("malloc"), NULL);
	i = malloc_loop(envp, not_included, &new_var);
	if (i == -1)
		return (NULL);
	new_var[i] = NULL;
	return (new_var);
}

int	remove_var(char *var_name, char **envp)
{
	int		index;
	char	**new_env;

	if (check_existing_var(var_name, envp))
	{
		index = find_env_index(envp, var_name);
		if (index == -1)
			return (0);
		new_env = malloc_copy_less(envp, index);
		if (!new_env)
			return (-1);
		free_env(envp);
		free(envp);
		set_minishell_env(new_env);
		return (0);
	}
	else
		return (0);
}
