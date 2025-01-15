/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:49 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/15 14:54:32 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *find_pipe(t_list *tokens)
{
	while(tokens)
	{
		if(*(char *)tokens->content == '|')
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

void setup_redirections(t_list *tokens, t_list *end)
{
	while(tokens != end)
	{
		if(is_operator_not_pipe(*(char *)tokens->content))
		{
			if(!ft_strncmp(tokens->content, ">>", 2))
				setup_output_redirection(tokens->next->content, 1);
			else if(!ft_strncmp(tokens->content, ">", 1))
				setup_output_redirection(tokens->next->content, 0);
			else if(!ft_strncmp(tokens->content, "<<", 2))
				setup_heredoc(tokens->next->content);
			else if(!ft_strncmp(tokens->content, "<", 1))
				setup_input_redirection(tokens->next->content);
		}
		tokens = tokens->next;
	}
}

int is_builtin(char *cmd)
{
	
}

void execute_tokens(t_list *tokens)
{
	t_list *pipe_ptr;

	// save stdin stdout
	pipe_ptr = find_pipe(tokens);
	if(pipe_ptr)
	{
		while(pipe_ptr)
		{
			// setup pipe
			// fork
			// if (pid == 0)
			// {
			// setup_redirections
			// check_cmd
			// if (builtin)
			// {
				// exec_builtin
				// exit
			// }
			// else
			// {
				// execve_cmd
			// }
			pipe_ptr = find_pipe(pipe_ptr->next);
		}
		// pid = fork
		// if (pid == 0)
		// {
		// 	setup_redirections
		// 	check_cmd
		// 	if (builtin)
		// 	{
		// 		exec_builtin
		// 		exit
		// 	}
		// 	else
		// 	{
		// 		execve_cmd
		// 	}
		// }
	}
	else
	{
		// setup_redirections
		// check_cmd
		// if (builtin)
		// {
			// exec_builtin
			// set_exit_code
		// }
		// else
		// {
			// pid = fork
			// if (pid == 0)
			// {
				// execve_cmd
			// }
		// }
	}
	// wait for all pids
	// reset stdin stdout
}
