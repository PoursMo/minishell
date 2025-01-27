/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 17:55:43 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_interactive_loop(void)
{
	char *input;
	t_list *tokens;

	while(1)
	{
		if (set_signals('i') == -1)
			return ;
		input = readline("minishell$ ");
		if (!input)
			actual_exit(EXIT_SUCCESS);
		add_to_history(input);
		// When exiting, need to clean_history()
		if (parse_input(input, &tokens) == -1)
			continue ;
		if (save_std_streams() == -1)
		{
			ft_lstclear(&tokens, free);
			continue ;
		}
		if (set_sigquit() == -1)
			return ;
		execute_tokens(tokens, get_child_pids());
		if (set_signals('r') == -1)
			return ;
		wait_for_processes(get_child_pids());
		ft_lstclear(&tokens, free);
		if (reset_std_streams() == -1)
			continue ;
	}
}

int setup_minishell(char **envp)
{
	set_minishell_env(create_new_env(envp));
	increment_shlvl(my_get_env("SHLVL"));
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
// remove .supp and valgrind rule from makefile
