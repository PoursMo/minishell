/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:16:22 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/21 14:43:16 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_and_frees2(const char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	free(s2);
	return (new_str);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void print_cmd_not_found(char *cmd)
{
	char *err;

	err = ft_strjoin(cmd, ": command not found\n");
	if (!err)
		return ;
	write(2, err, ft_strlen(err));
	free(err);
}

char	*find_cmd_path(char *cmd)
{
	char	**split_path;
	char	*joined_cmd;
	int		i;

	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		perror(cmd);
		exit(126);
	}
	split_path = ft_split(getenv("PATH"), ':');
	i = 0;
	while (split_path[i])
	{
		joined_cmd = ft_strdup(cmd);
		if (!joined_cmd)
			return (free_split(split_path), NULL);
		if (split_path[i][ft_strlen(*split_path) - 1] != '/')
		{
			joined_cmd = join_and_frees2("/", joined_cmd);
			if (!joined_cmd)
				return (free_split(split_path), NULL);
		}
		joined_cmd = join_and_frees2(split_path[i], joined_cmd);
		if (!joined_cmd)
			return (free_split(split_path), NULL);
		if (access(joined_cmd, F_OK) == 0)
		{
			free_split(split_path);
			if (access(joined_cmd, X_OK) == 0)
				return (joined_cmd);
			perror(cmd);
			free(joined_cmd);
			exit(126);
		}
		free(joined_cmd);
		i++;
	}
	free_split(split_path);
	print_cmd_not_found(cmd);
	exit(127);
}
