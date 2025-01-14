/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:18:23 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 15:23:26 by aloubry          ###   ########.fr       */
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
	if(!token)
		return (perror("make_token"), NULL);
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
	char *new_token_content;
	t_list *new_token;

	tokens = NULL;
	while (*input)
	{
		while (ft_isspace(*input))
			input++;
		if(*input)
		{
			new_token_content = make_token(input);
			if(!new_token_content)
				return (NULL);
			new_token = ft_lstnew(new_token_content);
			if(!new_token)
				return (free(new_token_content), NULL);
			ft_lstadd_back(&tokens, new_token);
			input += ft_strlen(ft_lstlast(tokens)->content);
		}
	}
	return (tokens);
}
