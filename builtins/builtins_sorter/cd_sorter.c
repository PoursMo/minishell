/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:16 by lbaecher          #+#    #+#             */
/*   Updated: 2025/02/03 08:48:13 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_sorter(char	**args)
{
	int		count;
	int		res;

	count = 0;
	while (args[count])
		count++;
	if (count > 2)
		return (printf("cd: too many arguments\n"), 1);
	if (count == 1)
	{
		if (!my_get_env("HOME"))
			return (printf("cd: HOME not set\n"), 1);
		res = change_directory(my_get_env("HOME"));
		return (res);
	}
	count = 1;
	if (args[count][0] == '\0')
		return (0);
	return (change_directory(args[1]));
}
