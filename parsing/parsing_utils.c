/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:22:01 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/08 13:47:49 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	toggle_quotes(int *single_quote, int *double_quote, char c)
{
	if (c == '"' && !*single_quote)
		*double_quote = !*double_quote;
	else if (c == '\'' && !*double_quote)
		*single_quote = !*single_quote;
}

void	minishell_toggle_quote(int *single_quote, int *double_quote, char *quote_start)
{
	int	i;

	toggle_quotes(single_quote, double_quote, *quote_start);
	if (*single_quote || *double_quote)
	{
		i = 1;
		while (quote_start[i])
		{
			if (*single_quote && quote_start[i] == '\'')
				break ;
			if (*double_quote && quote_start[i] == '"')
				break ;
			i++;
		}
		if (!quote_start[i])
			toggle_quotes(single_quote, double_quote, *quote_start);
	}
}
