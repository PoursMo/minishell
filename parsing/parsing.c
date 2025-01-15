/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:15:05 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/15 12:07:47 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_input(char *input, t_list *tokens)
{
	char	*expanded_input;

	expanded_input = expand_variables_of_input(input);
	if (!expanded_input)
		return (free(input), -1);
	free(input);
	tokens = tokenize_input(expanded_input);
	if (!tokens)
		return (free(expanded_input), -1);
	free(expanded_input);
	if (check_syntax_errors(tokens))
		return (ft_lstclear(&tokens, free), -1);
	return (0);
}
