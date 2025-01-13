/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:15:05 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/13 15:54:54 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_tokens(t_list *tokens)
{

}

int parse_input(char *input, t_list *tokens)
{
	char *expanded_input;

	expanded_input = expand_variables_of_input(input);
	free(input);
	tokens = tokenize_input(expanded_input);
	if(check_syntax_errors(tokens))
		return (free_tokens(tokens), -1);
	remove_quotes(tokens);
	return (0);
}