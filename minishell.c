/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/17 16:01:16 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
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

	//No parameters
	// display_all_env(environ);

	// //Add new;
	// printf("\n\n\n");
	// export_var("MY_ENV_VAR", "lol120", &environ);
	// display_all_env(environ);

	// //Change existing
	// printf("\n\n\n");
	// export_var("MY_ENV_VAR", "newlol", &environ);
	// display_all_env(environ);

	// (void)environ;
	// (void)argc;
	// (void)argv;
}