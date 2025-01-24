/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:58:40 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/23 17:25:51 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// exit_code.c

int		get_exit_code(void);
void	set_exit_code(int code);
int		get_exit_code_len(void);

// utils.c

int get_biggest(int a, int b);

// minishell_env.c

char	**get_minishell_env(void);
void	set_minishell_env(char **new_env);

// std_streams.c

int	save_std_streams(void);
int	reset_std_streams(void);
int *get_std_streams(void);

#endif