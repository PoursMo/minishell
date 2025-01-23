/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:23:42 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/23 12:38:39 by aloubry          ###   ########.fr       */
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
	if (tokens && *(char *)tokens->content == '|')
	{
		print_syntax_error("|");
		return (1);
	}
	while (tokens)
	{
		if (is_operator_not_pipe(*(char *)tokens->content)
			&& tokens->next && is_operator(*(char *)tokens->next->content))
			return (print_syntax_error(tokens->next->content), 1);
		if (is_operator(*(char *)tokens->content) && !tokens->next)
			return (print_syntax_error("newline"), 1);
		tokens = tokens->next;
	}
	return (0);
}
