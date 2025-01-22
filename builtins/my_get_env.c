/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:34:58 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 10:10:45 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_value_size(char *var)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (var[i] != '=')
		i++;
	i++;
	while (var[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char	*copy_var(int size, char *var)
{
	int		i;
	int		n_i;
	char	*new_var;

	i = 0;
	new_var = malloc(sizeof(char) * (size + 1));
	if (!new_var)
		return (NULL);
	while (var[i] != '=')
		i++;
	i++;
	n_i = 0;
	while (var[i] != '\0')
		new_var[n_i++] = var[i++];
	new_var[n_i] = '\0';
	return (new_var);
}

char	*my_get_env(char **env, char *var_name)
{
	int		size;
	char	*var;
	int		index;
	char	*return_var;

	index = find_env_index(env, var_name);
	if (index == -1)
		return (NULL);
	else
	{
		var = env[index];
		size = get_var_value_size(var);
		return_var = copy_var(size, var);
		if (!return_var)
			return (NULL);
	}
	return (return_var);
}
