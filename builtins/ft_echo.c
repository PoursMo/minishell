/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:17 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 09:20:23 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(int new_line_flag, char *str, int last)
{
	if (new_line_flag && !str)
		printf("\n");
	else if (new_line_flag && str)
		printf("%s\n", str);
	else if (!new_line_flag && str)
		printf("%s", str);
	if (!last)
		printf(" ");
}
