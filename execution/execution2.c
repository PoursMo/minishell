/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:41:57 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 19:03:34 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_cmd_args_size(t_list *cmd, t_list *end)
{
	int	size;

	size = 0;
	while (cmd != end)
	{
		if (is_operator_not_pipe(*(char *)cmd->content))
		{
			cmd = cmd->next->next;
			continue ;
		}
		size++;
		cmd = cmd->next;
	}
	return (size);
}

char	**get_cmd_args(t_list *cmd, t_list *end)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * (get_cmd_args_size(cmd, end) + 1));
	if (!args)
		return (perror("get_cmd_args"), NULL);
	i = 0;
	while (cmd != end)
	{
		if (is_operator_not_pipe(*(char *)cmd->content))
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

int	handle_builtin(t_list *tokens, t_list *cmd_ptr, t_list *pipe_ptr)
{
	size_t	cmd_len;
	char	**cmd_args;
	int		code;
	char	*cmd;

	cmd_args = get_cmd_args(cmd_ptr, pipe_ptr);
	cmd = cmd_ptr->content;
	cmd_len = ft_strlen(cmd);
	if (ft_strlen("echo") == cmd_len && !strncmp(cmd, "echo", cmd_len))
		code = echo_sorter(cmd_args);
	if (ft_strlen("cd") == cmd_len && !strncmp(cmd, "cd", cmd_len))
		code = cd_sorter(cmd_args);
	if (ft_strlen("pwd") == cmd_len && !strncmp(cmd, "pwd", cmd_len))
		code = get_pwd();
	if (ft_strlen("export") == cmd_len && !strncmp(cmd, "export", cmd_len))
		code = export_sorter(cmd_args);
	if (ft_strlen("unset") == cmd_len && !strncmp(cmd, "unset", cmd_len))
		code = unset_sorter(cmd_args);
	if (ft_strlen("env") == cmd_len && !strncmp(cmd, "env", cmd_len))
		code = env_sorter(cmd_args);
	if (ft_strlen("exit") == cmd_len && !strncmp(cmd, "exit", cmd_len))
		code = exit_w_status(tokens, cmd_args);
	free(cmd_args);
	return (code);
}

void	handle_non_builtin(t_list *cmd_ptr, t_list *pipe_ptr)
{
	char	*cmd;
	char	**cmd_args;

	cmd = find_cmd_path(cmd_ptr->content);
	if (!cmd)
		exit(EXIT_FAILURE);
	cmd_args = get_cmd_args(cmd_ptr, pipe_ptr);
	if (!cmd_args)
		exit(EXIT_FAILURE);
	if (execve(cmd, cmd_args, __environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
