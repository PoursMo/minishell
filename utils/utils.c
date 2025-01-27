/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:37:26 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/27 15:27:37 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_biggest(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_list	**get_child_pids(void)
{
	static t_list	*child_pids;

	return (&child_pids);
}
