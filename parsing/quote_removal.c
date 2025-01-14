/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:24:27 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 15:37:52 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	trim_token(char *token)
{
	int	is_in_single_quote;
	int	is_in_double_quote;

	is_in_single_quote = 0;
	is_in_double_quote = 0;
	while (*token)
	{
		if (*token == '"' && !is_in_single_quote)
		{
			if (minishell_toggle_quote(&is_in_double_quote, token))
			{
				ft_memmove(token, token + 1, ft_strlen(token));
				continue ;
			}
		}
		else if (*token == '\'' && !is_in_double_quote)
		{
			if (minishell_toggle_quote(&is_in_single_quote, token))
			{
				ft_memmove(token, token + 1, ft_strlen(token));
				continue ;
			}
		}
		token++;
	}
}

void	remove_quotes(t_list *tokens)
{
	while (tokens)
	{
		trim_token(tokens->content);
		tokens = tokens->next;
	}
}
