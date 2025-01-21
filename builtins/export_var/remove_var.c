/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:07:13 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/01/21 09:58:03 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_index(char **envp, char *var_name)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, ft_strlen(var_name)) == 0)
			if (envp[i][ft_strlen(var_name)] == '=')
				return (i);
		i++;
	}
	return (-1);
}

int	malloc_loop(char **envp, int n_i, char ***new_var)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (envp[y])
	{
		if (y == n_i)
			y++;
		else
		{
			(*new_var)[i] = ft_strdup(envp[y]);
			if (!((*new_var)[i]))
			{
				while (--i >= 0)
					free((*new_var)[i--]);
				return (free((*new_var)), -1); // MALLOC ERROR;
			}
			i++;
			y++;
		}
	}
	return (i);
}

char	**malloc_copy_less(char **envp, int not_included)
{
	int		i;
	int		last_index;
	char	**new_var;

	last_index = 0;
	while (envp[last_index])
		last_index++;
	new_var = malloc(sizeof(char *) * (last_index));
	if (!new_var)
		return (NULL); //MALLOC ERROR;
	i = malloc_loop(envp, not_included, &new_var);
	if (i == -1)
		return (NULL); //MALLOC ERROR
	new_var[i] = NULL;
	return (new_var);
}

int	remove_var(char *var_name, char ***envp)
{
	int	index;

	if (check_existing_var(var_name, *envp))
	{
		index = find_index(*envp, var_name);
		if (index == -1)
			return (0); //VAR NOT FOUND
		*envp = malloc_copy_less(*envp, index);
		if (!envp)
			return (-1); //MALLOC ERROR
		return (1);
	}
	else
		return (0);
}
