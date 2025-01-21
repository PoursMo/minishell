/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/21 16:33:28 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *input;
	t_list *tokens;

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
}
