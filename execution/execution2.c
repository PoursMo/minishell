/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:41:57 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/20 12:48:20 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int get_cmd_args_size(t_list *cmd, t_list *end)
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

void handle_builtin(t_list *cmd_ptr, t_list *pipe_ptr)
{
	fprintf(stderr, "Executing builtin command: %s\n", (char *)cmd_ptr->content);
	fprintf(stderr, "pipe_ptr: %s\n", (char *)pipe_ptr->content);
	// size_t cmd_len;

	// cmd_len = ft_strlen(cmd_ptr->content);
	// if (ft_strlen("echo") == cmd_len && !strncmp(cmd_ptr->content, "echo", cmd_len))
	// 	// echo
	// if (ft_strlen("cd") == cmd_len && !strncmp(cmd_ptr->content, "cd", cmd_len))
	// 	// cd
	// if (ft_strlen("pwd") == cmd_len && !strncmp(cmd_ptr->content, "pwd", cmd_len))
	// 	// pwd
	// if (ft_strlen("export") == cmd_len && !strncmp(cmd_ptr->content, "export", cmd_len))
	// 	// export
	// if (ft_strlen("unset") == cmd_len && !strncmp(cmd_ptr->content, "unset", cmd_len))
	// 	// unset
	// if (ft_strlen("env") == cmd_len && !strncmp(cmd_ptr->content, "env", cmd_len))
	// 	// env
	// if (ft_strlen("exit") == cmd_len && !strncmp(cmd_ptr->content, "exit", cmd_len))
	// 	// exit
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
