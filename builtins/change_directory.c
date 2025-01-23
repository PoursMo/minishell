/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:54:39 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 17:24:36 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//NEED TO CHECK LATER, WHEN MAIN LOOP EXISTS

int	change_directory(char *str)
{
	if (chdir(str) == -1)
		return (perror("chdir"), -1);
	return (export_var("PWD", str, get_minishell_env()));
}
