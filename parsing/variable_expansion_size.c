/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:49:25 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 18:03:00 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_var_size(char **var_start, int *size)
{
	char	*var_name;
	char	*var_value;

	var_name = get_var_name(*var_start + 1);
	if (!var_name)
		return (0);
	var_value = my_get_env(var_name);
	free(var_name);
	if (var_value)
		*size += ft_strlen(var_value);
	*var_start += get_var_name_size(*var_start + 1);
	return (1);
}

static int	handle_var(char **var_start, int *size)
{
	if (ft_isalpha(*(*var_start + 1)) || *(*var_start + 1) == '_')
		return (add_var_size(var_start, size));
	else if (*(*var_start + 1) == '?' || ft_isdigit(*(*var_start + 1)))
	{
		if (*(*var_start + 1) == '?')
			*size += get_exit_code_len();
		(*var_start)++;
		return (1);
	}
	else
		(*size)++;
	return (1);
}

int	get_expanded_size(char *input)
{
	int		size;
	int		is_in_single_quote;

	size = 0;
	is_in_single_quote = 0;
	while (*input)
	{
		if (*input == '\'')
			minishell_toggle_quote(&is_in_single_quote, input);
		if (*input == '$' && !is_in_single_quote)
		{
			if (!handle_var(&input, &size))
				return (-1);
		}
		else
			size++;
		input++;
	}
	return (size);
}
