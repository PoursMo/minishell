/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:58 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/10 15:02:50 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char *expand_variables_of_input(char *input);

t_list	*tokenize_input(char *input);

int	minishell_toggle_quote(int *quote, char *quote_start);
int	is_operator(int c);

int check_syntax_errors(t_list *tokens);

void remove_quotes(t_list *tokens);

//tester
void run_parsing_tests(void);

#endif