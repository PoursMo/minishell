/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:32 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/17 17:08:21 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

int is_builtin(char *cmd);

// redirection.c

int setup_redirections(t_list *start, t_list *end);

// command_checking.c

char *check_command(char *cmd);

#endif