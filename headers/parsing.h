/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:58 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/08 17:15:56 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char *expand_variables_of_input(char *input);

void tokenize_input(char *input);

void	minishell_toggle_quote(int *quote, char *quote_start);


#endif