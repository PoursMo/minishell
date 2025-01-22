/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:16 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 08:51:57 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_sorter(char	**args, char **new_env)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	if (count != 2)
		return (1); //Wrong number of arguments
	change_directory(args[1]);
	export_var("PWD", args[1], &new_env);
	return (0);
}