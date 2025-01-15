/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:32 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/15 14:28:22 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

void setup_input_redirection(const char *input_file);
void setup_output_redirection(const char *file, int mode);
void setup_heredoc(char *doc);

#endif