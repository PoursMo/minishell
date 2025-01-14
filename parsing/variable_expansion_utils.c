/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:00:07 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 21:03:40 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_var_name_size(char *var_start)
{
	int	size;

	size = 0;
	while (ft_isalnum(*var_start) || *var_start == '_')
	{
		size++;
		var_start++;
	}
	return (size);
}

char	*get_var_name(char *var_start)
{
	char	*var_name;
	int		i;

	var_name = malloc(sizeof(char) * (get_var_name_size(var_start) + 1));
	if (!var_name)
		return (perror("get_var_name"), NULL);
	i = 0;
	while (ft_isalnum(*var_start) || *var_start == '_')
		var_name[i++] = *var_start++;
	var_name[i] = '\0';
	return (var_name);
}
