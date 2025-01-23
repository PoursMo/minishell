/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:32 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/22 16:40:51 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

// redirection.c

int setup_redirections(t_list *start, t_list *end);

// command_checking.c

char *find_cmd_path(char *cmd);

// execution.c

void execute_tokens(t_list *tokens, t_list **pids);

// execution_pipeline.c

int execute_pipeline(t_list *tokens, t_list *pipe_ptr, t_list **pids);

// execution_utils.c

t_list *find_pipe_token(t_list *tokens);
t_list *find_cmd_token(t_list *tokens, t_list *end);
int is_builtin(char *cmd);
void	wait_for_processes(t_list **pids);

// execution2.c

char **get_cmd_args(t_list *cmd, t_list *end);
void handle_builtin(t_list *cmd_ptr, t_list *pipe_ptr);
void handle_non_builtin(t_list *cmd_ptr, t_list *pipe_ptr);

#endif