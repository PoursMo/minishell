/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:17:53 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/28 13:06:39 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_new_env(char **old_env)
{
	char	**new_env;

	if (!old_env)
	{
		new_env = NULL;
		return (new_env);
	}
	new_env = malloc_copy_env(old_env);
	return (new_env);
}
