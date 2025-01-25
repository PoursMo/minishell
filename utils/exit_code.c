/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:38:20 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/25 12:48:15 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_exit_code(int new_code)
{
	static unsigned int	code;

	if (new_code != -1)
	{
		code = new_code;
	}
	return (code);
}

int	get_exit_code(void)
{
	return (update_exit_code(-1));
}

void	set_exit_code(int code)
{
	fprintf(stderr, "setting exit code to %d\n", code);
	update_exit_code(code);
}

int	get_exit_code_len(void)
{
	int	len;
	int	code;

	code = update_exit_code(-1);
	len = 1;
	while (code)
	{
		len++;
		code /= 10;
	}
	return (len);
}
