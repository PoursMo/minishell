/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:58 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 17:40:53 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//variable_expansion.c

char	*expand_variables_of_input(char *input);

//tokenization.c

t_list	*tokenize_input(char *input);

//parsing_utils.c

int		minishell_toggle_quote(int *quote, char *quote_start);
int		is_operator(int c);
int		is_operator_not_pipe(int c);

//syntax_errors.c

int		check_syntax_errors(t_list *tokens);

//quote_removal.c

void	remove_quotes(t_list *tokens);

//tester
void run_parsing_tests(void);

#endif