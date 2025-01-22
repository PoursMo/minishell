/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/01/22 12:48:25 by aloubry          ###   ########.fr       */
=======
/*   Updated: 2025/01/22 14:00:11 by aloubry          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_empty_input(char *input)
{
	while(ft_isspace(*input))
		input++;
	if(!*input)
		return (1);
	return (0);
}

int main()
{
	char *input;
	t_list *tokens;
<<<<<<< Updated upstream

=======
	char	**new_env;
	t_list *pids;

	new_env = create_new_env(envp);
	set_minishell_env(envp);
	pids = NULL;
>>>>>>> Stashed changes
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
}
