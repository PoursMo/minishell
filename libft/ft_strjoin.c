/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:17:59 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/14 16:16:01 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*join;
	size_t	size;

	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	join = ft_calloc(sizeof(char), size);
	if (!join)
		return (perror("ft_strjoin"), NULL);
	ft_strlcat(join, str1, size);
	ft_strlcat(join, str2, size);
	return (join);
}
