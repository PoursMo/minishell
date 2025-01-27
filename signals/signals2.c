/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:08 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 15:47:02 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_sigquit(void)
{
	struct sigaction	sa_sigquit;

	sa_sigquit.sa_handler = SIG_DFL;
	sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	if (sigaction(SIGQUIT, &sa_sigquit, NULL) == -1)
		return (perror("sigaction"), -1);
	return (0);
}

int	set_signals(char mode)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	make_sigactions(mode, &sa_sigint, &sa_sigquit);
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
		return (perror("sigaction"), -1);
	if (sigaction(SIGQUIT, &sa_sigquit, NULL) == -1)
		return (perror("sigaction"), -1);
	return (0);
}
