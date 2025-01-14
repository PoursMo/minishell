/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:15:05 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 13:09:57 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parse_input(char *input, t_list *tokens)
{
	char *expanded_input;

	expanded_input = expand_variables_of_input(input);
	//protect expanded_input
	free(input);
	tokens = tokenize_input(expanded_input);
	//protect tokens
	if(check_syntax_errors(tokens))
		return (ft_lstclear(&tokens, free), -1);
	remove_quotes(tokens);
	return (0);
}