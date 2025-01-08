/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:22:01 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/08 17:15:07 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_toggle_quote(int *quote, char *quote_start)
{
	int i;

	if (!*quote)
	{
		i = 1;
		while(quote_start[i] && quote_start[i] != *quote_start)
			i++;
		if(quote_start[i])
			*quote = !*quote;
	}
	else
		*quote = !*quote;
}
