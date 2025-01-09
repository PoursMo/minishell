/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/09 11:32:24 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main()
{
	//char	*test;

	add_key_signals();
	//test = readline("minishell$ ");
	readline("minishell$ ");
	return (0);
}