/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checking_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:19:38 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 18:20:51 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_access(char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		perror(cmd);
		exit(126);
	}
	return (NULL);
}

char	**get_split_path(void)
{
	char	*path_env;

	path_env = my_get_env("PATH");
	if (!path_env)
		return (NULL);
	return (ft_split(path_env, ':'));
}

static char	*join_and_frees2(const char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	free(s2);
	return (new_str);
}

static char	*join_path_and_cmd(char *path, char *cmd)
{
	char	*result;

	result = ft_strdup(cmd);
	if (!result)
		return (NULL);
	if (path[ft_strlen(path) - 1] != '/')
	{
		result = join_and_frees2("/", result);
		if (!result)
			return (NULL);
	}
	result = join_and_frees2(path, result);
	return (result);
}

char	*find_in_path(char **split_path, char *cmd)
{
	int		i;
	char	*result;

	i = 0;
	while (split_path[i])
	{
		result = join_path_and_cmd(split_path[i], cmd);
		if (!result)
			return (free_split(split_path), NULL);
		if (access(result, F_OK) == 0)
		{
			free_split(split_path);
			if (access(result, X_OK) == 0)
				return (result);
			perror(cmd);
			free(result);
			exit(126);
		}
		free(result);
		i++;
	}
	return (NULL);
}
