/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 14:02:16 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int argc, char **argv, char **envp)
{
	char *input;
	t_list *tokens;
	char	**new_env;

	new_env = create_new_env(envp);
	set_minishell_env(envp);
	while(1)
	{
		input = readline(">");
		if (parse_input(input, &tokens) == -1) // gerer readline vide
			continue ;
		int tmp_stdin = dup(STDIN_FILENO);
		int tmp_stdout = dup(STDOUT_FILENO);
		execute_tokens(tokens);
		dup2(tmp_stdin, STDIN_FILENO);
		dup2(tmp_stdout, STDOUT_FILENO);
		ft_lstclear(&tokens, free);
	}
	free_env(&new_env);
	free(new_env);
	(void)argc;
	(void)argv;
}
