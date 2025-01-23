/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:17 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 13:34:16 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(int new_line_flag, char *str)
{
	if (new_line_flag && !str)
		return (printf("\n"), (void ) NULL);
	if (new_line_flag && str)
		return (printf("%s\n", str), (void ) NULL);
	if (!new_line_flag && !str)
		return ;
	else
		return (printf("%s", str), (void ) NULL);
}
