/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:04:17 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/05 15:34:44 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_instruction_data parse_instruction(char *instruction)
{
	t_instruction_data instruction_data;

	instruction_data.in_redirect_mode = -1;
	instruction_data.in_redirect_param = NULL;
	instruction_data.out_redirect_mode = -1;
	instruction_data.out_redirect_param = NULL;
	// while(*instruction)
	// {
		if(*instruction == '<' || *instruction == '>')
		{
			set_redirect_data(&instruction_data, instruction);
			// skip to end of redirect param
		}
		// instruction++;
	// }
	return (instruction_data);
}

int toggle_quotes(int *single_quote, int *double_quote, char c)
{
	if(c == '"' && !*single_quote)
	{
		*double_quote = !*double_quote;
		return (1);
	}
	else if(c == '\'' && !*double_quote)
	{
		*single_quote = !*single_quote;
		return (1);
	}
	return (0);
}

void	parse_input(char *input)
{
	char **instructions;

	instructions = ft_split(input, '|'); // malloc'd
	// protect malloc
	while(*instructions)
	{
		t_instruction_data data = parse_instruction(*instructions);
		// Print the parsed instruction data
		// printf("Command: ");
		// for (int i = 0; data.command && data.command[i]; i++)
		// 	printf("%s ", data.command[i]);
		printf("\nIn Redirect Mode: %d\n", data.in_redirect_mode);
		printf("In Redirect Param: %s\n", data.in_redirect_param);
		printf("Out Redirect Mode: %d\n", data.out_redirect_mode);
		printf("Out Redirect Param: %s\n", data.out_redirect_param);
		instructions++;
	}
}