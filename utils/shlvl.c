/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:42:07 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/28 14:00:28 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_shlvl(char *shlvl)
{
	int	i;

	i = 0;
	while (shlvl[i])
	{
		if (!ft_isdigit(shlvl[i]))
			return (1);
		i++;
	}
	return (0);
}

void	increment_shlvl(char *shlvl)
{
	char	*tmp;

	if (!shlvl || check_shlvl(shlvl) == 1)
	{
		export_var("SHLVL", "1", get_minishell_env());
		return ;
	}
	tmp = ft_itoa(ft_atoi(shlvl) + 1);
	if (!tmp)
		return ;
	export_var("SHLVL", tmp, get_minishell_env());
	free(tmp);
}
