/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/08 18:00:07 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
	char *expanded_input = expand_variables_of_input(argv[argc - 1]);
	printf("expanded input: %s\n", expanded_input);
	t_list *tokenized_expanded_input = tokenize_input(expanded_input);
	int token_number = 1;
	t_list *current = tokenized_expanded_input;
	while (current)
	{
		printf("token %d: %s\n", token_number, (char *)current->content);
		current = current->next;
		token_number++;
	}
}