/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/14 18:03:18 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
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

	get_pwd();
}