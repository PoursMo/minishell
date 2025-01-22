/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/22 12:42:18 by lbaecher         ###   ########.fr       */
=======
/*   Updated: 2025/01/22 14:07:23 by aloubry          ###   ########.fr       */
>>>>>>> execution
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
<<<<<<< HEAD
=======

int is_empty_input(char *input)
{
	while(ft_isspace(*input))
		input++;
	if(!*input)
		return (1);
	return (0);
}

>>>>>>> execution
int main(int argc, char **argv, char **envp)
{
	char *input;
	t_list *tokens;
<<<<<<< HEAD
	char	**new_env;

	new_env = create_new_env(envp);
	set_minishell_env(envp);
=======
	t_list *pids;

	(void)argc;
	(void)argv;
	(void)envp;
	pids = NULL;
>>>>>>> execution
	while(1)
	{
		input = readline(">");
		if (is_empty_input(input) || parse_input(input, &tokens) == -1)
			continue ;
		int tmp_stdin = dup(STDIN_FILENO);
		int tmp_stdout = dup(STDOUT_FILENO);
		execute_tokens(tokens, &pids);
		wait_for_processes(pids);
		dup2(tmp_stdin, STDIN_FILENO);
		dup2(tmp_stdout, STDOUT_FILENO);
		ft_lstclear(&tokens, free);
	}
	free_env(&new_env);
	free(&new_env);
	(void)argc;
	(void)argv;
}
