/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:46:36 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 11:52:21 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_sorter(char **args, char **new_env)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	if (count != 1)
		return ;
	display_all_env(new_env);
}
