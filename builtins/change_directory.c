/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:54:39 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 17:47:08 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//NEED TO CHECK LATER, WHEN MAIN LOOP EXISTS

int	change_directory(char *str)
{
	int		export_return;
	char	*curr_wd;

	curr_wd = NULL;
	if (chdir(str) == -1)
		return (perror("chdir"), -1);
	curr_wd = getcwd(curr_wd, 0);
	printf("%s\n", curr_wd);
	if (!curr_wd)
		return (perror("Malloc"), -1);
	export_return = export_var("PWD", curr_wd, get_minishell_env());
	free(curr_wd);
	return (export_return);
}
