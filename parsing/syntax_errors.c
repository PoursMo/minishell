/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:23:42 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 16:12:54 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_syntax_error(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

int	check_syntax_errors(t_list *tokens)
{
	if (tokens && ft_strchr(tokens->content, '|'))
	{
		print_syntax_error("|");
		return (1);
	}
	while (tokens)
	{
		if (is_operator_not_pipe(*(char *)tokens->content)
			&& (!tokens->next
				|| is_operator(*(char *)tokens->next->content)))
		{
			if (tokens->next)
				print_syntax_error(tokens->next->content);
			else
				print_syntax_error("newline");
			return (1);
		}
		if (!tokens->next && ft_strchr(tokens->content, '|'))
		{
			print_syntax_error("newline");
			return (1);
		}
		tokens = tokens->next;
	}
	return (0);
}
