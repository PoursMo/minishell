/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:57:19 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 09:34:33 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pwd(void)
{
	char	*str;

	str = NULL;
	str = getcwd(str, 0);
	if (!str)
		return (0);
	printf("%s\n", str);
	free(str);
	return (1);
}
