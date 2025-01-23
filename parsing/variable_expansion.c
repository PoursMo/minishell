/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:21:13 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/23 15:15:26 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*allocate_new_input(char *input)
{
	int		new_input_len;
	char	*new_input;

	new_input_len = get_expanded_size(input);
	if (new_input_len == -1)
		return (NULL);
	new_input = malloc(sizeof(char) * (new_input_len + 1));
	if (!new_input)
		return (perror("allocate_new_input"), NULL);
	return (new_input);
}

static int	add_var_to_new_input(char **var_start, int *i, char *new_input)
{
	char	*var_name;
	char	*var_value;

	var_name = get_var_name(*var_start + 1);
	if (!var_name)
		return (0);
	var_value = my_get_env(var_name);
	free(var_name);
	if (var_value)
	{
		ft_memcpy(&new_input[*i], var_value, ft_strlen(var_value));
		*i += ft_strlen(var_value);
	}
	*var_start += get_var_name_size(*var_start + 1);
	return (1);
}

static int	add_exitcode_to_new_input(char **var_start, int *i, char *new_input)
{
	char	*var_value;

	var_value = ft_itoa(get_exit_code());
	if (!var_value)
		return (0);
	ft_memcpy(&new_input[*i], var_value, ft_strlen(var_value));
	*i += ft_strlen(var_value);
	free(var_value);
	(*var_start)++;
	return (1);
}

static int	handle_var(char **var_start, int *i, char *new_input)
{
	if (ft_isalpha(*(*var_start + 1)) || *(*var_start + 1) == '_')
		return (add_var_to_new_input(var_start, i, new_input));
	else if (*(*var_start + 1) == '?')
		return (add_exitcode_to_new_input(var_start, i, new_input));
	else if (ft_isdigit(*(*var_start + 1)))
	{
		*var_start += 1;
		return (1);
	}
	else
		new_input[(*i)++] = **var_start;
	return (1);
}

char	*expand_variables_of_input(char *input)
{
	char	*new_input;
	int		is_in_single_quote;
	int		i;

	new_input = allocate_new_input(input);
	if (!new_input)
		return (NULL);
	is_in_single_quote = 0;
	i = 0;
	while (*input)
	{
		if (*input == '\'')
			minishell_toggle_quote(&is_in_single_quote, input);
		if (*input == '$' && !is_in_single_quote)
		{
			if (!handle_var(&input, &i, new_input))
				return (free(new_input), NULL);
		}
		else
			new_input[i++] = *input;
		input++;
	}
	new_input[i] = '\0';
	return (new_input);
}
