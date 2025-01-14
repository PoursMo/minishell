/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:18:23 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 17:36:27 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_tok_end(char c, int is_in_squote, int is_in_dquote)
{
	return (((!ft_isspace(c)) || is_in_squote || is_in_dquote)
		&& ((!is_operator(c)) || is_in_squote || is_in_dquote));
}

static void	handle_quotes(char *q_start, int *is_in_squote, int *is_in_dquote)
{
	if (*q_start == '"' && !*is_in_squote)
		minishell_toggle_quote(is_in_dquote, q_start);
	else if (*q_start == '\'' && !*is_in_dquote)
		minishell_toggle_quote(is_in_squote, q_start);
}

static int	get_token_size(char *token_start)
{
	int	size;
	int	is_in_squote;
	int	is_in_dquote;

	size = 0;
	is_in_squote = 0;
	is_in_dquote = 0;
	if (is_operator(*token_start))
	{
		size++;
		if (*token_start == *(token_start + 1)
			&& is_operator_not_pipe(*(token_start + 1)))
			size++;
	}
	while (*token_start && is_tok_end(*token_start, is_in_squote, is_in_dquote))
	{
		handle_quotes(token_start, &is_in_squote, &is_in_dquote);
		size++;
		token_start++;
	}
	return (size);
}

static char	*make_token(char *token_start)
{
	char	*token;
	int		is_in_squote;
	int		is_in_dquote;
	int		i;

	is_in_squote = 0;
	is_in_dquote = 0;
	token = malloc(sizeof(char) * (get_token_size(token_start) + 1));
	if (!token)
		return (perror("make_token"), NULL);
	i = 0;
	if (is_operator(*token_start))
	{
		token[i++] = *token_start;
		if (*token_start == *(token_start + 1)
			&& is_operator_not_pipe(*(token_start + 1)))
			token[i++] = *(token_start + 1);
	}
	while (*token_start && is_tok_end(*token_start, is_in_squote, is_in_dquote))
	{
		handle_quotes(token_start, &is_in_squote, &is_in_dquote);
		token[i++] = *token_start++;
	}
	token[i] = '\0';
	return (token);
}

t_list	*tokenize_input(char *input)
{
	t_list	*tokens;
	char	*new_token_content;
	t_list	*new_token;

	tokens = NULL;
	while (*input)
	{
		while (ft_isspace(*input))
			input++;
		if (*input)
		{
			new_token_content = make_token(input);
			if (!new_token_content)
				return (ft_lstclear(&tokens, free), NULL);
			new_token = ft_lstnew(new_token_content);
			if (!new_token)
				return (free(new_token_content),
					ft_lstclear(&tokens, free), NULL);
			ft_lstadd_back(&tokens, new_token);
			input += ft_strlen(ft_lstlast(tokens)->content);
		}
	}
	return (tokens);
}
