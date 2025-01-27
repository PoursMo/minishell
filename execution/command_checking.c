/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:16:22 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 18:22:07 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_cmd_not_found(char *cmd)
{
	char	*err;

	err = ft_strjoin(cmd, ": command not found\n");
	if (!err)
		return ;
	write(2, err, ft_strlen(err));
	free(err);
}

void	free_split(char **split)
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

char	*find_cmd_path(char *cmd)
{
	char	**split_path;
	char	*result;

	if (!*cmd)
	{
		print_cmd_not_found("''");
		exit(127);
	}
	result = check_access(cmd);
	if (result)
		return (result);
	split_path = get_split_path();
	if (!split_path)
	{
		print_cmd_not_found(cmd);
		exit(127);
	}
	result = find_in_path(split_path, cmd);
	if (result)
		return (result);
	free_split(split_path);
	print_cmd_not_found(cmd);
	exit(127);
}
