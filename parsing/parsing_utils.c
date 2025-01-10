/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:22:01 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/10 15:03:22 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_toggle_quote(int *quote, char *quote_start)
{
	int i;

	if (!*quote)
	{
		i = 1;
		while(quote_start[i] && quote_start[i] != *quote_start)
			i++;
		if(quote_start[i])
		{
			*quote = !*quote;
			return (1);
		}
	}
	else
	{
		*quote = !*quote;
		return (1);
	}
	return (0);
}

int	is_operator(int c)
{
	return (c == '>' || c == '<' || c == '|');
}
