/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:53:05 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/28 09:10:56 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_to_history(char *str)
{
	if (!(str[0]))
		return ;
	add_history(str);
}

void	clean_history(void)
{
	rl_clear_history();
}
