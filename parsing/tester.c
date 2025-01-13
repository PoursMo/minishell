/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:04:03 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/13 14:44:27 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void test_loop(char *command)
{
	printf("--------------------\ntesting on input : \x1B[35m %s\n\x1B[0m", command);
    char *expanded_input = expand_variables_of_input(command);
    printf("expanded input: %s\n", expanded_input);
    t_list *tokenized_expanded_input = tokenize_input(expanded_input);
    free(expanded_input);
    int token_number = 1;
    t_list *current = tokenized_expanded_input;
    while (current)
    {
        printf("token %d: %s\n", token_number, (char *)current->content);
        current = current->next;
        token_number++;
    }
	if(!check_syntax_errors(tokenized_expanded_input))
		printf("no syntax error\n");
	else
		return ;
	remove_quotes(tokenized_expanded_input);
	printf("removing quotes...\n");
	token_number = 1;
    current = tokenized_expanded_input;
    while (current)
    {
        printf("token %d: %s\n", token_number, (char *)current->content);
        current = current->next;
        token_number++;
    }
    ft_lstclear(&tokenized_expanded_input, free);
}

void run_parsing_tests(void)
{
    // Array of test commands
    char *test_commands[] = {
        "echo Hello World",
        "ls -l /home",
        "pwd",
        "echo $HOME",
        "echo $USER",
        "echo \"User: $USER, Home: $HOME\"",
        "echo 'User: $USER, Home: $HOME'",
        "ls -l | grep minishell",
        "cat file.txt | wc -l",
        "echo \"Hello World\" > output.txt  ",
        "cat < input.txt",
        "cat input.txt > output.txt",
        "echo \"Hello World\" >> output.txt",
        "cat input.txt >> output.txt",
        "ls -l | grep minishell > result.txt",
        "cat file.txt | wc -l >> count.txt",
        "echo \"Hello World\" |",
        "echo \"Hello World\" >",
        "echo \"Hello World\" >>",
        "echo \"Hello World\" <",
		"| echo \"Hello World\"",
        "echo \"Special characters: !@#$%^&*()_+\"",
		"echo 'Hello \"World\"'",
		"echo \"Hello 'World'\"",
		"\"\"",
		"''",
		"       ", // spaces
		"		", // tabs
		"echo \"\"",
		"echo $?",
        ""
    };

	int i = 0;
	while(test_commands[i][0])
	{
		test_loop(test_commands[i]);
		i++;
	}
	test_loop(test_commands[i]);
}