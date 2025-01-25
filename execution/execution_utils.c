/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:37:08 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/25 12:51:58 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_pipe_token(t_list *tokens)
{
	while (tokens)
	{
		if (*(char *)tokens->content == '|')
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

t_list	*find_cmd_token(t_list *tokens, t_list *end)
{
	while (tokens != end && is_operator_not_pipe(*(char *)tokens->content))
		tokens = tokens->next->next;
	if (tokens == end)
		return (NULL);
	return (tokens);
}

int	is_builtin(char *cmd)
{
	const char	*builtins[] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit", NULL};
	int			i;
	size_t		cmd_len;

	cmd_len = ft_strlen(cmd);
	i = 0;
	while (builtins[i])
	{
		if (ft_strlen(builtins[i]) == cmd_len
			&& !strncmp(cmd, builtins[i], cmd_len))
			return (1);
		i++;
	}
	return (0);
}

void	wait_for_processes(t_list **pids)
{
	t_list	*tmp;
	int		status;

	tmp = *pids;
	while (tmp)
	{
		if (waitpid(*(int *)tmp->content, &status, 0) != -1)
			set_exit_code(WEXITSTATUS(status));
		tmp = tmp->next;
	}
	ft_lstclear(pids, free);
}
