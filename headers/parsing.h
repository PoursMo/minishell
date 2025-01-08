/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:58 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/08 14:11:53 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char *expand_variables_of_input(char *input);

void tokenize_input(char *input);

void toggle_quotes(int *single_quote, int *double_quote, char c);
void	minishell_toggle_quotes(int *single_quote, int *double_quote, char *quote_start);

#endif