/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 12:57:55 by lbaecher         ###   ########.fr       */
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
		// set interactive signals
		input = readline("minishell$ ");
		add_history(input);
		// When exiting, need to clean_history()
		// set running signals
		if (parse_input(input, &tokens) == -1)
			continue ;
		if (save_std_streams() == -1)
		{
			ft_lstclear(&tokens, free);
			continue ;
		}
		execute_tokens(tokens, &pids);
		ft_lstclear(&tokens, free);
		wait_for_processes(&pids);
		if (reset_std_streams() == -1)
			continue ;
	}
}

int setup_minishell(char **envp)
{
	set_minishell_env(create_new_env(envp));
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
// remove valgrind rule from makefile + ignore_readline_leaks.supp