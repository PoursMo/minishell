/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:57:19 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/23 17:22:06 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pwd(void)
{
	char	*str;

	str = NULL;
	str = getcwd(str, 0);
	if (!str)
		return (perror("Malloc"), -1);
	printf("%s\n", str);
	free(str);
	return (0);
}
