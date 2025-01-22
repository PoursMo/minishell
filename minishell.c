/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 16:41:32 by aloubry          ###   ########.fr       */
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
		// set running signals
		if (parse_input(input, &tokens) == -1)
			continue ;
		for (t_list *temp = tokens; temp != NULL; temp = temp->next)
		{
			printf("Token: %s\n", (char *)temp->content);
		}
		if (save_std_streams() == -1)
		{
			ft_lstclear(&tokens, free);
			continue ;
		}
		execute_tokens(tokens, &pids);
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
