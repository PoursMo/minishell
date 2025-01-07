/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:18:23 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/07 18:55:49 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void toggle_quotes(int *single_quote, int *double_quote, char c)
{
	if(c == '"' && !*single_quote)
		*double_quote = !*double_quote;
	else if(c == '\'' && !*double_quote)
		*single_quote = !*single_quote;
}

int is_operator(int c)
{
	return (c == '>' || c == '<' || c == '|');
}

char *make_token(char *token_start)
{
	char *token;
	int is_in_single_quote;
	int is_in_double_quote;
	int i;

	// malloc token
	token = malloc(sizeof(char) * 100);
	// protect malloc
	is_in_single_quote = 0;
	is_in_double_quote = 0;
	toggle_quotes(&is_in_single_quote, &is_in_double_quote, *token_start);
	i = 1;
	while(token_start[i])
	{
		if(is_in_single_quote && token_start[i] == '\'')
			break ;
		if(is_in_double_quote && token_start[i] == '"')
			break ;
		i++;
	}
	if(!token_start[i])
		toggle_quotes(&is_in_single_quote, &is_in_double_quote, *token_start);
	i = 0;
	if(is_operator(*token_start) && !is_in_single_quote && !is_in_double_quote)
	{
		token[i++] = *token_start;
		if(*token_start == *(token_start + 1) && (*(token_start + 1) == '<' || *(token_start + 1) == '>'))
			token[i++] = *(token_start + 1);
	}
	while(*token_start && ((!ft_isspace(*token_start)) || is_in_single_quote || is_in_double_quote)
		&& ((!is_operator(*token_start)) || is_in_single_quote || is_in_double_quote))
	{
		token[i++] = *token_start;
		token_start++;
	}
	token[i] = '\0';
	return (token);
}

void tokenize_input(char *input)
{
	char **tokens;
	int tokens_index;

	// malloc tokens
	tokens = malloc(sizeof(char *) * 100);
	// protect malloc
	tokens_index = 0;
	while(*input)
	{
		while(ft_isspace(*input))
			input++;
		tokens[tokens_index] = make_token(input);
		input += ft_strlen(tokens[tokens_index]);
		tokens_index++;
	}
	tokens[tokens_index] = NULL;
	
	// debug
	for (int i = 0; tokens[i] != NULL; i++)
	{
		printf("Token %d: %s\n", i, tokens[i]);
		free(tokens[i]);
	}
	free(tokens);
	// end of debug
}


// echo "Hello" >| file ?????