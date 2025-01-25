/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/25 13:00:48 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_interactive_loop(void)
{
	char *input;
	t_list *tokens;

	while(1)
	{
		set_signals('i');
		input = readline("minishell$ ");
		add_history(input);
		// When exiting, need to clean_history()
		// set running signals
		if (!input)
			exit(EXIT_SUCCESS);
		if (parse_input(input, &tokens) == -1)
			continue ;
		if (save_std_streams() == -1)
		{
			ft_lstclear(&tokens, free);
			continue ;
		}
		set_sigquit();
		execute_tokens(tokens, get_child_pids());
		set_signals('r');
		wait_for_processes(get_child_pids());
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
	char	*char_shlvl;

	set_minishell_env(create_new_env(envp));
	char_shlvl = my_get_env("SHLVL");
	char_shlvl[0] += 1;
	export_var("SHLVL", char_shlvl, get_minishell_env());
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