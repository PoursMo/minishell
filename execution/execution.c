/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:49 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 18:38:45 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_no_pipeline_non_builtin(t_list *cmd_ptr, t_list **pids)
{
	int		*pid;
	t_list	*new_pid;

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
	return (0);
}

int	execute_no_pipeline(t_list *tokens, t_list **pids)
{
	t_list	*cmd_ptr;

	if (setup_redirections(tokens, NULL) == -1)
		return (set_exit_code(EXIT_FAILURE), -1);
	cmd_ptr = find_cmd_token(tokens, NULL);
	if (!cmd_ptr)
		return (set_exit_code(EXIT_SUCCESS), -1);
	remove_quotes(cmd_ptr->content);
	if (is_builtin(cmd_ptr->content))
		set_exit_code(handle_builtin(tokens, cmd_ptr, NULL));
	else
		if (handle_no_pipeline_non_builtin(cmd_ptr, pids) == -1)
			return (-1);
	return (0);
}

void	execute_tokens(t_list *tokens, t_list **pids)
{
	t_list	*pipe_ptr;

	pipe_ptr = find_pipe_token(tokens);
	if (pipe_ptr)
	{
		while (pipe_ptr)
		{
			if (execute_pipeline(tokens, pipe_ptr, pids) == -1)
				return ;
			tokens = pipe_ptr->next;
			pipe_ptr = find_pipe_token(tokens);
		}
		if (execute_pipeline(tokens, pipe_ptr, pids) == -1)
			return ;
	}
	else
	{
		if (execute_no_pipeline(tokens, pids) == -1)
			return ;
	}
}
