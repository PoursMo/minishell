/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:17:53 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/21 10:19:36 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_new_env(char **old_env)
{
	int		index;
	char	**new_env;

	index = find_index(old_env, "_");
	new_env = malloc_copy_less(old_env, index);
	return (new_env);
}