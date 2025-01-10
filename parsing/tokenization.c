/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:18:23 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/10 13:59:22 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_token_size(char *token_start)
{
	int	size;
	int	is_in_single_quote;
	int	is_in_double_quote;

	size = 0;
	is_in_single_quote = 0;
	is_in_double_quote = 0;
	if (is_operator(*token_start) && !is_in_single_quote && !is_in_double_quote)
	{
		size++;
		if (*token_start == *(token_start + 1) && (*(token_start + 1) == '<' || *(token_start + 1) == '>'))
			size++;
	}
	while (*token_start && ((!ft_isspace(*token_start)) || is_in_single_quote || is_in_double_quote)
		&& ((!is_operator(*token_start)) || is_in_single_quote || is_in_double_quote))
	{
		if(*token_start == '"' && !is_in_single_quote)
			minishell_toggle_quote(&is_in_double_quote, token_start);
		else if(*token_start == '\'' && !is_in_double_quote)
			minishell_toggle_quote(&is_in_single_quote, token_start);
		size++;
		token_start++;
	}
	return (size);
}

static char	*make_token(char *token_start)
{
	char	*token;
	int		is_in_single_quote;
	int		is_in_double_quote;
	int		i;

	is_in_single_quote = 0;
	is_in_double_quote = 0;
	token = malloc(sizeof(char) * (get_token_size(token_start) + 1));
	// protect malloc
	i = 0;
	if (is_operator(*token_start))
	{
		token[i++] = *token_start;
		if (*token_start == *(token_start + 1) && (*(token_start + 1) == '<' || *(token_start + 1) == '>'))
			token[i++] = *(token_start + 1);
	}
	while (*token_start && ((!ft_isspace(*token_start)) || is_in_single_quote || is_in_double_quote)
		&& ((!is_operator(*token_start)) || is_in_single_quote || is_in_double_quote))
	{
		if(*token_start == '"' && !is_in_single_quote)
			minishell_toggle_quote(&is_in_double_quote, token_start);
		else if(*token_start == '\'' && !is_in_double_quote)
			minishell_toggle_quote(&is_in_single_quote, token_start);
		token[i++] = *token_start;
		token_start++;
	}
	token[i] = '\0';
	return (token);
}

t_list	*tokenize_input(char *input)
{
	t_list	*tokens;

	tokens = NULL;
	while (*input)
	{
		while (ft_isspace(*input))
			input++;
		if(*input)
		{
			ft_lstadd_back(&tokens, ft_lstnew(make_token(input)));
			//protect mallocs
			input += ft_strlen(ft_lstlast(tokens)->content);
		}
	}
	return (tokens);
}

// echo "Hello" >| file ?????