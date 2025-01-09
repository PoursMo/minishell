/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:07 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/09 11:36:43 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The add_key_signals must be added when launching the shell so that ctrl-c
// behaves properly

#include "minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_redisplay();
		rl_on_new_line();
		usleep(200000);
		exit (0);
	}
	if (sig == SIGQUIT)
		return ;
}

static void	add_ctrl_d(void)
{
	printf("%d\n",isatty(STDIN_FILENO));
	printf("%d\n",ttyslot());
}

void	add_key_signals(void)
{
	struct	sigaction sig;

	sig.sa_handler = &sig_handler;
	sigaction(SIGQUIT, &sig, NULL);
	sigaction(SIGINT, &sig, NULL);
	add_ctrl_d();
}