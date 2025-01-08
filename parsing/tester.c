/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:04:03 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/08 18:12:04 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
        "echo \"Hello \\\"World\\\"\"",
        "echo 'Hello \\'World\\''",
        "ls -l | grep minishell",
        "cat file.txt | wc -l",
        "echo \"Hello World\" > output.txt",
        "cat < input.txt",
        "cat input.txt > output.txt",
        "echo \"Hello World\" >> output.txt",
        "cat input.txt >> output.txt",
        "ls -l | grep minishell > result.txt",
        "cat file.txt | wc -l >> count.txt",
        "sleep 10 &",
        "ls -l &",
        "(cd /home && ls)",
        "(echo \"Hello\" && echo \"World\")",
        "echo \"Hello\" && echo \"World\"",
        "false || echo \"This will be printed\"",
        "echo \"Starting process\" && (cd /home && ls) | grep minishell > result.txt",
        "echo \"Hello World\" |",
        "echo \"Hello World\" >",
        "echo \"Hello World\" >>",
        "echo \"Hello World\" <",
        "echo \"Special characters: !@#$%^&*()_+\"",
        ""
    };

    for (int i = 0; test_commands[i][0] != '\0'; i++)
    {
		printf("--------------------\ntesting on input : \x1B[35m %s\n\x1B[0m", test_commands[i]);
        char *expanded_input = expand_variables_of_input(test_commands[i]);
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
        free(expanded_input);
        ft_lstclear(&tokenized_expanded_input, free);
    }
}