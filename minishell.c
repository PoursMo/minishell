/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 11:45:00 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	// int	fd;

	// fd = open("builtins/output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644 );
	// dup2(fd, STDOUT_FILENO);

	// //ft_echo(1, "hello");
	// //Output.txt should contain "Hello" and another line

	// ft_echo(0, "hello");
	// //Output.txt should contain "Hello"
	// return (0);

	//change_directory("/builtins");

	//EXPORT

	// No parameters
	char **new_environ;
	char *args[3];

	args[0] = "export";
	args[1] = "TEST55839123";
	args[2] = NULL;
	new_environ = create_new_env(envp);
	//display_all_env(envp);
	export_sorter(args, &new_environ);
	display_all_export(new_environ);
	printf("\n\n\n\n\n");
	unset_sorter(args, &new_environ);
	display_all_export(new_environ);
	// printf("\nPREVIOUS LIST SHOULD CONTAIN THE \"_\" VAR AND NOT BE ORDERED\n");
	//display_all_export(new_environ);

	// // // //Add new;
	// printf("\n\n\n");
	// export_var("MY_ENV_VAR", "first_value", &new_environ);
	// printf("End of first phase\n");
	// display_all_export(new_environ);

	// // //Change existing
	// printf("\n\n\n");
	// export_var("MY_ENV_VAR", "second_value", &new_environ);
	// display_all_export(new_environ);

	// // // // // Remove var
	// printf("\n\n\n");
	// remove_var("MY_ENV_VAR", &new_environ);
	// display_all_export(new_environ);

	free_env(&new_environ);
	free(new_environ);
	(void)argc;
	(void)argv;
}