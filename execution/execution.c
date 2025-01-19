/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:49 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/19 19:30:01 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *find_pipe_token(t_list *tokens)
{
	while (tokens)
	{
		if (*(char *)tokens->content == '|')
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

t_list *find_cmd_token(t_list *tokens, t_list *end)
{
	while (is_operator_not_pipe(*(char *)tokens->content) && tokens != end)
		tokens = tokens->next->next;
	if (tokens == end)
		return (NULL);
	return (tokens);
}

int get_cmd_args_size(t_list *cmd, t_list *end)
{
	int size;

	size = 0;
	cmd = cmd->next;
	while(cmd != end)
	{
		if(is_operator_not_pipe(*(char *)cmd->content))
		{
			cmd = cmd->next->next;
			continue ;
		}
		size++;
		cmd = cmd->next;
	}
	return (size);
}

char **get_cmd_args(t_list *cmd, t_list *end)
{
	char **args;
	int i;

	args = malloc(sizeof(char *) * get_cmd_args_size(cmd, end) + 1);
	if (!args)
		return (perror("get_cmd_args"), NULL);
	i = 0;
	while(cmd != end)
	{
		if(is_operator_not_pipe(*(char *)cmd->content))
		{
			cmd = cmd->next->next;
			continue ;
		}
		remove_quotes(cmd->content);
		args[i++] = cmd->content;
		cmd = cmd->next;
	}
	args[i] = NULL;
	return (args);
}

int is_builtin(char *cmd)
{
	const char *builtins[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	int i;

	i = 0;
	while (builtins[i])
	{
		if (!strncmp(cmd, builtins[i], get_biggest(ft_strlen(cmd), ft_strlen(builtins[i]))))
			return (1);
		i++;
	}
	return (0);
}

int setup_pipe_out_redirection(int pipe_fds[2])
{
	if (close(pipe_fds[0]) == -1)
		perror("close"); // return -1 ?
	if (dup2(pipe_fds[1], STDOUT_FILENO) == -1)
		return(perror("dup2"), -1);
	if (close(pipe_fds[1]) == -1)
		perror("close"); // return -1 ?
	return (0);
}

int setup_pipe_in_redirection(int pipe_fds[2])
{
	if (close(pipe_fds[1]) == -1)
		perror("close"); // return -1 ?
	if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
		return (perror("dup2"), -1);
	if (close(pipe_fds[0]) == -1)
		perror("close"); // return -1 ?
	return (0);
}

void handle_builtin(t_list *cmd_ptr, t_list *pipe_ptr)
{
	fprintf(stderr, "cmd_ptr: %s\n", (char *)cmd_ptr->content); // debug
	fprintf(stderr, "pipe_ptr: %s\n", (char *)pipe_ptr->content); // debug
}

void handle_non_builtin(t_list *cmd_ptr, t_list *pipe_ptr)
{
	char *cmd;
	char **cmd_args;
	
	cmd = find_cmd_path(cmd_ptr->content);
	if(!cmd)
		exit(EXIT_FAILURE);
	fprintf(stderr, "full cmd: %s\n", cmd); // debug
	cmd_args = get_cmd_args(cmd_ptr, pipe_ptr);
	if (!cmd_args)
		exit(EXIT_FAILURE);
	for (int j = 0; cmd_args[j]; j++) // debug
		fprintf(stderr, "cmd_args[%d]: %s\n", j, cmd_args[j]); // debug
	if (execve(cmd, cmd_args, __environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void handle_pipeline_child_exec(t_list *tokens, t_list *pipe_ptr, int pipe_fds[2])
{
	t_list *cmd_ptr;
	
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

int execute_pipeline(t_list *tokens, t_list *pipe_ptr, t_list **pids)
{
	int pipe_fds[2];
	int *pid;
	t_list *new_pid;
	
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
	fprintf(stderr, "pid: %d\n", *pid); // debug
	new_pid = ft_lstnew(pid);
	if (!new_pid)
		return (free(pid), -1);
	ft_lstadd_back(pids, new_pid);
	if (pipe_ptr && setup_pipe_in_redirection(pipe_fds) == -1)
		return (-1);
	return (0);
}

void wait_for_processes(t_list *pids)
{
	t_list *tmp;
	int status;
	
	tmp = pids;
	while (tmp)
	{
		waitpid(*(int *)tmp->content, &status, 0);
		set_exit_code(status);
		tmp = tmp->next;
	}
	ft_lstclear(&pids, free);
}

void execute_tokens(t_list *tokens)
{
	t_list *pipe_ptr;
	t_list *pids = NULL;
	int *pid;
	t_list *cmd_ptr;

	// save stdin stdout
	pipe_ptr = find_pipe_token(tokens);
	fprintf(stderr, "pipe_ptr: %p, content: %s\n", pipe_ptr, pipe_ptr ? (char *)pipe_ptr->content : "NULL"); // debug
	if (pipe_ptr)
	{
		while (pipe_ptr)
		{
			if (execute_pipeline(tokens, pipe_ptr, &pids) == -1)
				return ; // free des trucs
			tokens = pipe_ptr->next;
			pipe_ptr = find_pipe_token(tokens);
		}
		if (execute_pipeline(tokens, pipe_ptr, &pids) == -1)
			return ; // free des trucs
	}
	else
	{
		if (setup_redirections(tokens, pipe_ptr) == -1)
		{
			set_exit_code(EXIT_FAILURE);
			return ; // free des trucs
		}
		cmd_ptr = find_cmd_token(tokens, pipe_ptr);
		if (!cmd_ptr)
		{
			set_exit_code(EXIT_SUCCESS);
			return ; // free des trucs
		}
		fprintf(stderr, "cmd_ptr content: %s\n", (char *)cmd_ptr->content); // debug
		remove_quotes(cmd_ptr->content);
		if (is_builtin(cmd_ptr->content))
		{
			// exec_builtin
			// return + success ?
		}
		else
		{
			pid = malloc(sizeof(int));
			// protect
			*pid = fork();
			if (*pid == -1)
			{
				perror("fork");
				return ; // free des trucs
			}
			if (*pid == 0)
				handle_non_builtin(cmd_ptr, pipe_ptr);
			fprintf(stderr, "pid: %d\n", *pid); // debug
			t_list *new_pid = ft_lstnew(pid);
			// malloc check
			ft_lstadd_back(&pids, new_pid);
		}
	}
	wait_for_processes(pids);
	// reset stdin stdout
}
