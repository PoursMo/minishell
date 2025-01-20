/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:49 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/20 19:11:48 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_no_pipeline(t_list *tokens, t_list **pids)
{
	t_list *cmd_ptr;
	int *pid;
	t_list *new_pid;
	
	if (setup_redirections(tokens, NULL) == -1)
		return (set_exit_code(EXIT_FAILURE), -1);
	cmd_ptr = find_cmd_token(tokens, NULL);
	if (!cmd_ptr)
		return (set_exit_code(EXIT_SUCCESS), -1);
	fprintf(stderr, "cmd_ptr content: %s\n", (char *)cmd_ptr->content); // debug
	remove_quotes(cmd_ptr->content);
	if (is_builtin(cmd_ptr->content))
	{
		handle_builtin(cmd_ptr, NULL);
		set_exit_code(EXIT_SUCCESS);
	}
	else
	{
		pid = malloc(sizeof(int));
		if (!pid)
			return (perror("execute_no_pipeline"), -1);
		*pid = fork();
		if (*pid == -1)
			return (perror("fork"), free(pid), -1);
		if (*pid == 0)
			handle_non_builtin(cmd_ptr, NULL);
		new_pid = ft_lstnew(pid);
		if (!new_pid)
			return (free(pid), -1);
		ft_lstadd_back(pids, new_pid);
	}
	return (0);
}

void execute_tokens(t_list *tokens)
{
	t_list *pipe_ptr;
	t_list *pids = NULL;

	// save stdin stdout
	pipe_ptr = find_pipe_token(tokens);
	fprintf(stderr, "pipe_ptr: %p, content: %s\n", pipe_ptr, pipe_ptr ? (char *)pipe_ptr->content : "NULL"); // debug
	if (pipe_ptr)
	{
		while (pipe_ptr)
		{
			if (execute_pipeline(tokens, pipe_ptr, &pids) == -1)
				return ; // free des trucs + exit code
			tokens = pipe_ptr->next;
			pipe_ptr = find_pipe_token(tokens);
		}
		if (execute_pipeline(tokens, pipe_ptr, &pids) == -1)
			return ; // free des trucs + exit code
	}
	else
	{
		if (execute_no_pipeline(tokens, &pids) == -1)
			return ; // free des trucs + exit code
	}
	wait_for_processes(pids);
	// reset stdin stdout
}
