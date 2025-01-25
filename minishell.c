/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/24 13:20:57 by loicbaecher      ###   ########.fr       */
=======
/*   Updated: 2025/01/25 12:08:29 by aloubry          ###   ########.fr       */
>>>>>>> signals
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
<<<<<<< HEAD
		add_history(input);
		// When exiting, need to clean_history()
		// set running signals
=======
		if (!input)
			exit(EXIT_SUCCESS);
>>>>>>> signals
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
<<<<<<< HEAD
	char	*char_shlvl;

	set_minishell_env(create_new_env(envp));
	char_shlvl = my_get_env("SHLVL");
	char_shlvl[0] += 1;
	export_var("SHLVL", char_shlvl, get_minishell_env());
=======
	(void)envp;
	// create env
	// incr SHLVL
	// history stuff
>>>>>>> signals
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