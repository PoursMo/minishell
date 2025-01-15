/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:06:40 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 12:47:59 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_bubble_sort(char **new_env)
{
	char	*temp;
	int		i;

	i = 0;
	while (new_env[i] && new_env[i + 1])
	{
		if (ft_strncmp(new_env[i], new_env[i + 1], ft_strlen(new_env[i])) > 0)
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

char	**malloc_copy_env(char **environ)
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

int	is_same_env_var(char *var_name, char *environ_line)
{
	int	y;

	y = 0;
	while (environ_line[y] != '=' && var_name[y])
	{
		if (environ_line[y] != var_name[y])
			return (0) ;
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
	while(var_name[i])
		new_var[c++] = var_name[i++];
	i = 0;
	new_var[c++] = '=';
	while(val[i])
		new_var[c++] = val[i++];
	new_var[c] = '\0';
	return(new_var);
}
