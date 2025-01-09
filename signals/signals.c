/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:07 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/09 15:30:38 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The add_key_signals must be added when launching the shell so that ctrl-c
// behaves properly

#include "minishell.h"

static void	sig_interactive(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_redisplay();
		rl_on_new_line();
		printf("\nTHIS MUST BE CHANGED TO GO TO NEWLINE:\n");
		printf("Exiting minishell...\n");
		usleep(200000);
		exit (0);
	}
}

void	add_signals(char c)
{
	struct sigaction	sig_sigint;
	struct sigaction	sig_sigquit;

	if (c == 'i')
	{
		sig_sigint.sa_handler = &sig_interactive;
		sig_sigquit.sa_handler = SIG_IGN;
		sigaction(SIGINT, &sig_sigint, NULL);
		sigaction(SIGQUIT, &sig_sigquit, NULL);
	}
}
