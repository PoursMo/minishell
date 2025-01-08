/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:18:23 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/08 13:30:34 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_operator(int c)
{
	return (c == '>' || c == '<' || c == '|');
}

static void	init_quotes(int *single_quote, int *double_quote, char *token_start)
{
	int	i;

	*single_quote = 0;
	*double_quote = 0;
	toggle_quotes(single_quote, double_quote, *token_start);
	i = 1;
	while (token_start[i])
	{
		if (*single_quote && token_start[i] == '\'')
			break ;
		if (*double_quote && token_start[i] == '"')
			break ;
		i++;
	}
	if (!token_start[i])
		toggle_quotes(single_quote, double_quote, *token_start);
}

static int	get_token_size(char *token_start, int is_in_single_quote, int is_in_double_quote)
{
	int	size;

	size = 0;
	if (is_operator(*token_start) && !is_in_single_quote && !is_in_double_quote)
	{
		size++;
		if (*token_start == *(token_start + 1) && (*(token_start + 1) == '<' || *(token_start + 1) == '>'))
			size++;
	}
	while (*token_start && ((!ft_isspace(*token_start)) || is_in_single_quote || is_in_double_quote)
		&& ((!is_operator(*token_start)) || is_in_single_quote || is_in_double_quote))
	{
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

	init_quotes(&is_in_single_quote, &is_in_double_quote, token_start);
	token = malloc(sizeof(char) * (get_token_size(token_start, is_in_single_quote, is_in_double_quote) + 1));
	// protect malloc
	i = 0;
	if (is_operator(*token_start) && !is_in_single_quote && !is_in_double_quote)
	{
		token[i++] = *token_start;
		if (*token_start == *(token_start + 1) && (*(token_start + 1) == '<' || *(token_start + 1) == '>'))
			token[i++] = *(token_start + 1);
	}
	while (*token_start && ((!ft_isspace(*token_start)) || is_in_single_quote || is_in_double_quote)
		&& ((!is_operator(*token_start)) || is_in_single_quote || is_in_double_quote))
	{
		token[i++] = *token_start;
		token_start++;
	}
	token[i] = '\0';
	return (token);
}

void	tokenize_input(char *input)
{
	t_list	*tokens;
	int		tokens_index;

	tokens_index = 0;
	while (*input)
	{
		while (ft_isspace(*input))
			input++;
		ft_lstadd_back(&tokens, ft_lstnew(make_token(input)));
		//protect mallocs
		input += ft_strlen(ft_lstlast(tokens)->content);
		tokens_index++;
	}
	// debug
	t_list *current = tokens;
	while (current)
	{
		printf("Token: %s\n", (char *)current->content);
		current = current->next;
	}
	// end of debug
}


// echo "Hello" >| file ?????