/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:13:31 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/22 12:20:57 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**update_minishell_env(char **new_env)
{
	static char	**minishell_env;

	if (new_env)
	{
		minishell_env = new_env;
	}
	return (minishell_env);
}

char	**get_minishell_env(void)
{
	return (update_minishell_env(NULL));
}

void	set_minishell_env(char **new_env)
{
	update_minishell_env(new_env);
}
