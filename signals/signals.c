/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:07 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/08 19:02:05 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_redisplay();
		rl_on_new_line();
		printf("Exiting...This exit must be removed\n");
		usleep(200000);
	}
}

void	add_key_signals(void)
{
	struct	sigaction sig;

	sig.sa_handler = &sig_handler;
	sigaction(SIGINT, &sig, NULL);
}