/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:54:39 by lbaecher          #+#    #+#             */
/*   Updated: 2025/02/03 09:33:37 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_directory(char *str)
{
	int		export_return;
	char	*error_msg;
	char	*curr_wd;

	curr_wd = NULL;
	if (chdir(str) == -1)
	{
		error_msg = ft_strjoin("cd: ", str);
		if (!error_msg)
			return (perror("malloc"), -1);
		perror(error_msg);
		free(error_msg);
		return (1);
	}
	curr_wd = getcwd(curr_wd, 0);
	if (!curr_wd)
		return (perror("malloc"), -1);
	export_return = export_var("PWD", curr_wd, get_minishell_env());
	free(curr_wd);
	return (export_return);
}
