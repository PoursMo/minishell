/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:46:36 by lbaecher          #+#    #+#             */
/*   Updated: 2025/02/03 08:48:04 by lbaecher         ###   ########.fr       */
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
		return (printf("env: too many arguments\n"), -1);
	return (display_all_env(get_minishell_env()));
}
