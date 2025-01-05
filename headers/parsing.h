/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:58 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/05 14:54:39 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_instruction_data
{
	char **command;
	int in_redirect_mode;
	char *in_redirect_param; // malloc'd if not NULL
	int out_redirect_mode;
	char *out_redirect_param; // malloc'd if not NULL
} t_instruction_data;


//redirect.c

void set_redirect_data(t_instruction_data *instruction_data, char *string);

//parsing.c

int toggle_quotes(int *single_quote, int *double_quote, char c);
void	parse_input(char *input);

#endif