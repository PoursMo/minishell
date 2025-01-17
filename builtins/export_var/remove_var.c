/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:07:13 by loicbaecher       #+#    #+#             */
/*   Updated: 2025/01/17 16:22:52 by loicbaecher      ###   ########.fr       */
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

	last_index = 0;
	while (envp[last_index])
		last_index++;
	new_var = malloc(sizeof(char *) * (last_index - 1));
	if (!new_var)
		return (NULL); //MALLOC ERROR;
	i = 0;
	while (envp[i])
	{
		if (!(i == not_included))
		{
			new_var[i] = ft_strdup(envp[i]);
			if (!new_var[i])
			{
				while (--i >= 0)
					free(new_var[i--]);
				return (free(new_var), NULL); // MALLOC ERROR;
			}
		}
		i++;
	}
	new_var[i] = NULL;
	return (new_var);
}

int	remove_var(char *var_name, char ***envp)
{
	int	index;
	char	**new_env;
	index = find_index(*envp, var_name);
	printf("INDEX : %d\n", index);
	if (index == -1)
		return (0); //VAR NOT FOUND
	new_env = malloc_copy_less(*envp, index);
	if (!new_env)
		return (-1); //MALLOC ERROR
	return (1);
}