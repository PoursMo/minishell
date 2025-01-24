/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:46:36 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 14:57:09 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_sorter(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	if (count != 1)
		return (perror("env: too many arguments"), -1);
	return (display_all_env(get_minishell_env()));
}
