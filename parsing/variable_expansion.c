/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:21:13 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/13 15:33:50 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int get_var_name_size(char *var_start)
{
	int size;

	size = 0;
	while(ft_isalnum(*var_start) || *var_start == '_')
	{
		size++;
		var_start++;	
	}
	return (size);
}

static char *get_var_name(char *var_start)
{
	char *var_name;
	int i;

	var_name = malloc(sizeof(char) * (get_var_name_size(var_start) + 1));
	// protect malloc
	i = 0;
	while(ft_isalnum(*var_start) || *var_start == '_')
		var_name[i++] = *var_start++;
	var_name[i] = '\0';
	return (var_name);
}

static int get_expanded_size(char *input)
{
	int size;
	char *var_name;
	char *var_value;
	int is_in_single_quote;

	is_in_single_quote = 0;
	size = 0;
	while(*input)
	{
		if(*input == '\'')
			minishell_toggle_quote(&is_in_single_quote, input);
		if(*input == '$' && !is_in_single_quote)
		{
			if(ft_isalpha(*(input + 1)) || *(input + 1) == '_')
			{
				var_name = get_var_name(input + 1);
				var_value = getenv(var_name);
				free(var_name);
				if(var_value)
					size += ft_strlen(var_value);
				input += get_var_name_size(input + 1);
			}
			else if(*(input + 1) == '?')
			{
				//get exit num
				//size += len of exit num
				input++;
			}
		}
		else
			size++;
		input++;
	}
	return (size);
}

char *expand_variables_of_input(char *input)
{
	char *new_input;
	int is_in_single_quote;
	char *var_name;
	char *var_value;
	int i;

	new_input = malloc(sizeof(char) * (get_expanded_size(input) + 1));
	// protect malloc
	is_in_single_quote = 0;
	i = 0;
	while(*input)
	{
		if(*input == '\'')
			minishell_toggle_quote(&is_in_single_quote, input);
		if(*input == '$' && !is_in_single_quote)
		{
			if(ft_isalpha(*(input + 1)) || *(input + 1) == '_')
			{
				var_name = get_var_name(input + 1);
				var_value = getenv(var_name);
				free(var_name);
				if(var_value)
				{
					ft_memcpy(&new_input[i], var_value, ft_strlen(var_value));
					i += ft_strlen(var_value);
				}
				input += get_var_name_size(input + 1);
			}
			else if(*(input + 1) == '?')
			{
				// get and cpy last exit num
				// i += len of exit num
				input++;
			}
			else if(ft_isdigit(*(input + 1)))
				input++;
			else
				new_input[i++] = *input;
		}
		else
			new_input[i++] = *input;
		input++;
	}
	new_input[i] = '\0';
	return (new_input);
}