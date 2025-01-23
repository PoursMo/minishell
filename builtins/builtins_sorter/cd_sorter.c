/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:16 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 16:35:42 by loicbaecher      ###   ########.fr       */
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
		return (perror("cd: too many arguments"), 1);
	if (count == 1)
	{
		res = change_directory(my_get_env("HOME"));
		return (res);
	}
	if (!args[count])
	{
		res = change_directory(my_get_env("HOME"));
		return (res);
	}
	return (change_directory(args[1]));
}
