/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:07 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/24 17:20:06 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The add_key_signals must be added when launching the shell so that ctrl-c
// behaves properly

#include "minishell.h"

void handle_interactive_sigint(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	set_exit_code(130);
}

void handle_running_sigint(int signal)
{
	(void)signal;
	if (kill(0, SIGINT) == -1)
		perror("kill");
	set_exit_code(130);
}

void handle_running_sigquit(int signal)
{
	(void)signal;
	set_exit_code(131);
}

int set_interactive_signals(void)
{
	struct sigaction sa_sigint;
	struct sigaction sa_sigquit;

	sa_sigint.sa_handler = handle_interactive_sigint;
	sa_sigquit.sa_handler = SIG_IGN;
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
		return (perror("sigaction"), -1);
	if (sigaction(SIGQUIT, &sa_sigquit, NULL) == -1)
		return (perror("sigaction"), -1);
	return (0);
}

int set_running_signals(void)
{
	struct sigaction sa_sigint;
	struct sigaction sa_sigquit;

	sa_sigint.sa_handler = handle_running_sigint;
	sa_sigquit.sa_handler = handle_running_sigquit;
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
		return (perror("sigaction"), -1);
	if (sigaction(SIGQUIT, &sa_sigquit, NULL) == -1)
		return (perror("sigaction"), -1);
	return (0);
}


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
