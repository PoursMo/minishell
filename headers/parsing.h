/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:58 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/15 12:15:15 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//variable_expansion.c

char	*expand_variables_of_input(char *input);

//variable_expansion_size.c

int		get_expanded_size(char *input);

//variable_expansion_utils.c

int		get_var_name_size(char *var_start);
char	*get_var_name(char *var_start);

//tokenization.c

t_list	*tokenize_input(char *input);

//parsing_utils.c

int		minishell_toggle_quote(int *quote, char *quote_start);
int		is_operator(int c);
int		is_operator_not_pipe(int c);

//syntax_errors.c

int		check_syntax_errors(t_list *tokens);

//quote_removal.c

void	remove_quotes(char *token);



void run_parsing_tests(void); //tester

#endif