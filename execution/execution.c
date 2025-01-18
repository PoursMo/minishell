/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:49 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/18 18:44:33 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *find_pipe(t_list *tokens)
{
	while (tokens)
	{
		if (*(char *)tokens->content == '|')
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

t_list *find_cmd(t_list *tokens, t_list *end)
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

void execute_tokens(t_list *tokens)
{
	t_list *pipe_ptr;
	t_list *pids = NULL;
	int *pid;
	t_list *cmd_ptr;
	char *cmd;
	char **cmd_args;
	int pipe_fds[2];

	// save stdin stdout
	pipe_ptr = find_pipe(tokens);
	fprintf(stderr, "pipe_ptr: %p, content: %s\n", pipe_ptr, pipe_ptr ? (char *)pipe_ptr->content : "NULL");
	if (pipe_ptr)
	{
		while (pipe_ptr)
		{
			if (pipe(pipe_fds) == -1)
			{
				perror("pipe");
				return ;
			}
			pid = malloc(sizeof(int));
			// protect
			*pid = fork();
			if (*pid == -1)
			{
				perror("fork");
				return ;
			}
			if (*pid == 0)
			{
				if (close(pipe_fds[0]) == -1)
					perror("close"); // exit ?
				if (dup2(pipe_fds[1], STDOUT_FILENO) == -1)
				{
					perror("dup2");
					exit(EXIT_FAILURE);
				}
				if (close(pipe_fds[1]) == -1)
					perror("close"); // exit ?
				if (!setup_redirections(tokens, pipe_ptr))
					exit(EXIT_FAILURE);
				cmd_ptr = find_cmd(tokens, pipe_ptr);
				if (!cmd_ptr)
					exit(EXIT_SUCCESS);
				fprintf(stderr, "cmd_ptr content: %s\n", (char *)cmd_ptr->content);
				remove_quotes(cmd_ptr->content);
				if (is_builtin(cmd_ptr->content))
				{
					// exec_builtin
					exit(EXIT_SUCCESS);
				}
				else
				{
					cmd = check_command(cmd_ptr->content);
					if(!cmd)
						exit(EXIT_FAILURE);
					fprintf(stderr, "full cmd: %s\n", cmd);
					cmd_args = get_cmd_args(cmd_ptr, pipe_ptr);
					if (!cmd_args)
						exit(EXIT_FAILURE);
					for (int j = 0; cmd_args[j]; j++)
						fprintf(stderr, "cmd_args[%d]: %s\n", j, cmd_args[j]);
					if (execve(cmd, cmd_args, __environ) == -1)
					{
						perror("execve");
						exit(EXIT_FAILURE);
					}
				}
			}
			fprintf(stderr, "pid: %d\n", *pid);
			t_list *new_pid = ft_lstnew(pid);
			// malloc check
			ft_lstadd_back(&pids, new_pid);
			if (close(pipe_fds[1]) == -1)
				perror("close"); // return ?
			if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
			{
				perror("dup2");
				return ;
			}
			if (close(pipe_fds[0]) == -1)
				perror("close"); // return ?
			tokens = pipe_ptr->next;
			pipe_ptr = find_pipe(tokens);
		}
		pid = malloc(sizeof(int));
		// protect
		*pid = fork();
		if (*pid == -1)
		{
			perror("fork");
			return ;
		}
		if (*pid == 0)
		{
			if (!setup_redirections(tokens, pipe_ptr))
				exit(EXIT_FAILURE);
			cmd_ptr = find_cmd(tokens, pipe_ptr);
			if (!cmd_ptr)
				exit(EXIT_SUCCESS);
			fprintf(stderr, "cmd_ptr content: %s\n", (char *)cmd_ptr->content);
			remove_quotes(cmd_ptr->content);
			if (is_builtin(cmd_ptr->content))
			{
				// exec_builtin
				exit(EXIT_SUCCESS);
			}
			else
			{
				cmd = check_command(cmd_ptr->content);
				if(!cmd)
					exit(EXIT_FAILURE);
				fprintf(stderr, "full cmd: %s\n", cmd);
				cmd_args = get_cmd_args(cmd_ptr, pipe_ptr);
				if (!cmd_args)
					exit(EXIT_FAILURE);
				for (int j = 0; cmd_args[j]; j++)
					fprintf(stderr, "cmd_args[%d]: %s\n", j, cmd_args[j]);
				if (execve(cmd, cmd_args, __environ) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
		}
		fprintf(stderr, "pid: %d\n", *pid);
		t_list *new_pid = ft_lstnew(pid);
		// malloc check
		ft_lstadd_back(&pids, new_pid);
	}
	else
	{
		if (!setup_redirections(tokens, pipe_ptr))
		{
			set_exit_code(EXIT_FAILURE);
			return ;
		}
		cmd_ptr = find_cmd(tokens, pipe_ptr);
		if (!cmd_ptr)
		{
			set_exit_code(EXIT_SUCCESS);
			return ;
		}
		fprintf(stderr, "cmd_ptr content: %s\n", (char *)cmd_ptr->content);
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
				return ;
			}
			if (*pid == 0)
			{
				cmd = check_command(cmd_ptr->content);
				if(!cmd)
				{
					set_exit_code(EXIT_FAILURE);
					return ;
				}
				fprintf(stderr, "full cmd: %s\n", cmd);
				cmd_args = get_cmd_args(cmd_ptr, pipe_ptr);
				if (!cmd_args)
				{
					set_exit_code(EXIT_FAILURE);
					return ;
				}
				for (int j = 0; cmd_args[j]; j++)
					fprintf(stderr, "cmd_args[%d]: %s\n", j, cmd_args[j]);
				if (execve(cmd, cmd_args, __environ) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			fprintf(stderr, "pid: %d\n", *pid);
			t_list *new_pid = ft_lstnew(pid);
			// malloc check
			ft_lstadd_back(&pids, new_pid);
		}
	}
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
	// reset stdin stdout
}
