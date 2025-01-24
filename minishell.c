/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/24 16:28:30 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_interactive_loop(void)
{
	char *input;
	t_list *tokens;
	t_list *pids;

	pids = NULL;
	while(1)
	{
		set_interactive_signals();
		input = readline("minishell$ ");
		if (!input)
			exit(EXIT_SUCCESS);
		if (parse_input(input, &tokens) == -1)
			continue ;
		if (save_std_streams() == -1)
		{
			ft_lstclear(&tokens, free);
			continue ;
		}
		execute_tokens(tokens, &pids);
		set_running_signals();
		wait_for_processes(&pids);
		if (reset_std_streams() == -1)
		{
			ft_lstclear(&tokens, free);
			continue ;
		}
		ft_lstclear(&tokens, free);
	}
}

int setup_minishell(char **envp)
{
	(void)envp;
	// create env
	// incr SHLVL
	// history stuff
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	if (setup_minishell(envp) == -1)
		return (EXIT_FAILURE);
	run_interactive_loop();
}

// remove -g from makefile