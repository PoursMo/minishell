/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:07 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 15:47:06 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_interactive_sigint(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	set_exit_code(130);
}

static void	handle_heredoc_sigint(int signal)
{
	(void)signal;
	write(get_std_streams()[STDOUT_FILENO], "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	set_exit_code(130);
}

static void	handle_running_sigint(int signal)
{
	t_list	*pids;

	(void)signal;
	pids = *get_child_pids();
	while (pids)
	{
		kill(*(int *)pids->content, SIGINT);
		pids = pids->next;
	}
	set_exit_code(130);
}

static void	handle_running_sigquit(int signal)
{
	t_list	*pids;

	(void)signal;
	pids = *get_child_pids();
	while (pids)
	{
		kill(*(int *)pids->content, SIGQUIT);
		pids = pids->next;
	}
	write(2, "Quit\n", 5);
	set_exit_code(131);
}

void	make_sigactions(char mode,
	struct sigaction *sa_sigint, struct sigaction *sa_sigquit)
{
	sa_sigint->sa_flags = 0;
	sigemptyset(&sa_sigint->sa_mask);
	sa_sigquit->sa_flags = 0;
	sigemptyset(&sa_sigquit->sa_mask);
	if (mode == 'i')
	{
		sa_sigint->sa_handler = handle_interactive_sigint;
		sa_sigquit->sa_handler = SIG_IGN;
	}
	else if (mode == 'r')
	{
		sa_sigint->sa_handler = handle_running_sigint;
		sa_sigquit->sa_handler = handle_running_sigquit;
	}
	else if (mode == 'h')
	{
		sa_sigint->sa_handler = handle_heredoc_sigint;
		sa_sigquit->sa_handler = SIG_IGN;
	}
}
