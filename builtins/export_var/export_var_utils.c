/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:06:40 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/17 15:24:18 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_bubble_sort(char **new_env)
{
	char	*temp;
	size_t	max_size;
	int		i;

	i = 0;
	while (new_env[i] && new_env[i + 1])
	{
		max_size = ft_strlen(new_env[i]);
		if (ft_strlen(new_env[i + 1]) > max_size)
			max_size = ft_strlen(new_env[i + 1]);
		if (ft_strncmp(new_env[i], new_env[i + 1], max_size) > 0)
		{
			temp = new_env[i];
			new_env[i] = new_env[i + 1];
			new_env[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (new_env);
}

char	**malloc_copy_env(char **envp)
{
	int		i;
	int		last_index;
	char	**new_var;

	last_index = 0;
	while (envp[last_index])
		last_index++;
	new_var = malloc(sizeof(char *) * last_index);
	if (!new_var)
		return (NULL); //MALLOC ERROR;
	i = 0;
	while (envp[i])
	{
		new_var[i] = ft_strdup(envp[i]);
		if (!new_var[i])
		{
			while (--i >= 0)
				free(new_var[i--]);
			return (free(new_var), NULL); // MALLOC ERROR;
		}
		i++;
	}
	envp[i] = NULL;
	return (new_var);
}

char	**malloc_add_var(char **envp, int *index)
{
	int		i;
	int		len;
	char	**new_var;

	len = 0;
	while(envp[len])
		len++;
	new_var = malloc(sizeof(char *) * (len + 2));
	if (!new_var)
		return (NULL); //MALLOC ERROR;
	i = 0;
	while (envp[i])
	{
		new_var[i] = ft_strdup(envp[i]);
		if (!new_var[i])
		{
			while (--i >= 0)
				free(new_var[i--]);
			return (free(new_var), NULL); // MALLOC ERROR
		}
		i++;
	}
	*index = i;
	return (new_var);
}

int	is_same_env_var(char *var_name, char *environ_line)
{
	int	y;

	y = 0;
	while (environ_line[y] != '=' && var_name[y])
	{
		if (environ_line[y] != var_name[y])
			return (0);
		y++;
	}
	if (environ_line[y] == '=' && var_name[y] == '\0')
		return (1);
	return (0);
}

char	*fill_env_str(char *new_var, char *var_name, char *val)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (var_name[i])
		new_var[c++] = var_name[i++];
	i = 0;
	new_var[c++] = '=';
	while (val[i])
		new_var[c++] = val[i++];
	new_var[c] = '\0';
	return (new_var);
}
