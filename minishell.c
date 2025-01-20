/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:44:35 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/20 12:52:41 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	t_list *tokens;

	char *input = "echo";
	char *mallocd_input = malloc(sizeof(char) * (ft_strlen(input) + 1));
	ft_strlcpy(mallocd_input, input, ft_strlen(input) + 1);

	if (parse_input(mallocd_input, &tokens) == -1)
		return 1;
	execute_tokens(tokens);
}
