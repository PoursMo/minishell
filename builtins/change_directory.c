/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:54:39 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/14 18:03:55 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//NEED TO CHECK LATER, WHEN MAIN LOOP EXISTS

void	change_directory(char	*str)
{
	int	res;

	res = chdir(str);
	printf("res : %d", res);
}