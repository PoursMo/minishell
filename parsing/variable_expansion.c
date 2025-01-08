/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:21:13 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/08 14:45:15 by aloubry          ###   ########.fr       */
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

char *get_var_name(char *var_start)
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

char *expand_variables_of_input(char *input)
{
	// char *new_input;
	int is_in_single_quote;
	
	// malloc new_input
	// protect malloc
	is_in_single_quote = 0;
	while(*input)
	{
		if(*input == '\'')
			minishell_toggle_quotes(&is_in_single_quote, NULL, input);
		if(*input == '$' && !is_in_single_quote)
		{
			if(ft_isalpha(*(input + 1)) || *(input + 1) == '_')
				printf("name: %s\n", get_var_name(input + 1));
		}
		input++;
	}
	return NULL;
}