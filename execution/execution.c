/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:49 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/17 17:09:10 by aloubry          ###   ########.fr       */
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

t_list *find_cmd(t_list *tokens)
{
	while(is_operator_not_pipe(*(char *)tokens->content))
		tokens = tokens->next->next;
	return (tokens);
}

int is_builtin(char *cmd)
{
	const char *builtins[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	int i;

	i = 0;
	while(builtins[i])
	{
		if(!strncmp(cmd, builtins[i], get_biggest(ft_strlen(cmd), ft_strlen(builtins[i]))))
			return (1);
		i++;
	}
	return (0);
}

// void execute_tokens(t_list *tokens)
// {
// 	t_list *pipe_ptr;
// 	t_list *pids;
// 	int pid;
// 	t_list *cmd_ptr;
// 	int pipe_fds[2];

// 	// save stdin stdout
// 	pipe_ptr = find_pipe(tokens);
// 	if(pipe_ptr)
// 	{
// 		while(pipe_ptr)
// 		{
// 			if (pipe(pipe_fds) == -1)
// 			{
// 				perror("pipe");
// 				return ;
// 			}
// 			pid = fork();
// 			if(pid == -1)
// 			{
// 				perror("fork");
// 				return ;
// 			}
// 			// ptr lstnew(pid)
// 			ft_lstadd_back(pids, ft_lstnew(pid));
// 			if(ft_lstlast(pids)->content == 0)
// 			{
// 				// setup pipe
// 				if (!setup_redirections(tokens, pipe_ptr))
// 					exit(EXIT_FAILURE);
// 				cmd_ptr = find_cmd(tokens);
// 				if (is_builtin(cmd_ptr->content))
// 				{
// 					// exec_builtin
// 					exit(EXIT_SUCCESS);
// 				}
// 				else
// 				{
// 					// check_cmd
// 					// execve_cmd
// 				}
// 			}
// 			tokens = pipe_ptr->next;
// 			pipe_ptr = find_pipe(tokens);
// 		}
// 		// pid = fork
// 		// if (pid == 0)
// 		// {
// 		// 	setup_redirections
// 		// 	check_cmd
// 		// 	if (builtin)
// 		// 	{
// 		// 		exec_builtin
// 		// 		exit
// 		// 	}
// 		// 	else
// 		// 	{
// 		// 		execve_cmd
// 		// 	}
// 		// }
// 	}
// 	else
// 	{
// 		// setup redirection
// 		// if (builtin)
// 		// {
// 			// exec_builtin
// 			// set_exit_code
// 		// }
// 		// else
// 		// {
// 			// pid = fork
// 			// if (pid == 0)
// 			// {
// 				// check_cmd
// 				// execve_cmd
// 			// }
// 		// }
// 	}
// 	// wait for all pids
// 	// lstclear pids
// 	// reset stdin stdout
// }
