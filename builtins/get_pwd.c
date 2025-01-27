/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:57:19 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 08:28:26 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pwd(void)
{
	char	*str;

	str = NULL;
	str = getcwd(str, 0);
	if (!str)
		return (perror("malloc"), -1);
	printf("%s\n", str);
	free(str);
	return (0);
}
