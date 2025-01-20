/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:07:13 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/01/20 16:56:44 by loicbaecher      ###   ########.fr       */
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
				return(i);
		i++;
	}
	return (-1);
}

char	**malloc_copy_less(char **envp, int not_included)
{
	int		i;
	int		last_index;
	char	**new_var;
	int		y;

	last_index = 0;
	while (envp[last_index])
		last_index++;
	new_var = malloc(sizeof(char *) * (last_index));
	if (!new_var)
		return (NULL); //MALLOC ERROR;
	i = 0;
	y = 0;
	while (envp[y])
	{
		if (y == not_included)
		{
			printf("YES\n");
			y++;
		}
		else
		{
			new_var[i] = ft_strdup(envp[y]);
			if (!new_var[i])
			{
				while (--i >= 0)
					free(new_var[i--]);
				return (free(new_var), NULL); // MALLOC ERROR;
			}
			i++;
			y++;

		}
	}
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