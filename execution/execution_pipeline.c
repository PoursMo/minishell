/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:37:44 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/20 12:51:32 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setup_pipe_out_redirection(int pipe_fds[2])
{
	if (close(pipe_fds[0]) == -1)
		perror("close"); // return -1 ?
	if (dup2(pipe_fds[1], STDOUT_FILENO) == -1)
		return (perror("dup2"), -1);
	if (close(pipe_fds[1]) == -1)
		perror("close"); // return -1 ?
	return (0);
}

static int	setup_pipe_in_redirection(int pipe_fds[2])
{
	if (close(pipe_fds[1]) == -1)
		perror("close"); // return -1 ?
	if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
		return (perror("dup2"), -1);
	if (close(pipe_fds[0]) == -1)
		perror("close"); // return -1 ?
	return (0);
}

static void	handle_pipeline_child_exec(t_list *tokens, t_list *pipe_ptr, int pipe_fds[2])
{
	t_list	*cmd_ptr;

	if (pipe_ptr && setup_pipe_out_redirection(pipe_fds) == -1)
		exit(EXIT_FAILURE);
	if (setup_redirections(tokens, pipe_ptr) == -1)
		exit(EXIT_FAILURE);
	cmd_ptr = find_cmd_token(tokens, pipe_ptr);
	if (!cmd_ptr)
		exit(EXIT_SUCCESS);
	fprintf(stderr, "cmd_ptr content: %s\n", (char *)cmd_ptr->content); // debug
	remove_quotes(cmd_ptr->content);
	if (is_builtin(cmd_ptr->content))
	{
		handle_builtin(cmd_ptr, pipe_ptr);
		exit(EXIT_SUCCESS);
	}
	else
		handle_non_builtin(cmd_ptr, pipe_ptr);
}

int	execute_pipeline(t_list *tokens, t_list *pipe_ptr, t_list **pids)
{
	int		pipe_fds[2];
	int		*pid;
	t_list	*new_pid;

	if (pipe(pipe_fds) == -1)
		return (perror("pipe"), -1);
	pid = malloc(sizeof(int));
	if (!pid)
		return (perror("execute_pipeline"), -1);
	*pid = fork();
	if (*pid == -1)
		return (perror("fork"), free(pid), -1);
	if (*pid == 0)
		handle_pipeline_child_exec(tokens, pipe_ptr, pipe_fds);
	new_pid = ft_lstnew(pid);
	if (!new_pid)
		return (free(pid), -1);
	ft_lstadd_back(pids, new_pid);
	if (pipe_ptr && setup_pipe_in_redirection(pipe_fds) == -1)
		return (-1);
	return (0);
}
