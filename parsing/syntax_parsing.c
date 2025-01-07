/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:23:42 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/07 16:50:19 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void print_syntax_error(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected token '|'\n", 2);
	//start reading a new line and change $? code
}

void check_syntax_errors(char *input)
{
	
}