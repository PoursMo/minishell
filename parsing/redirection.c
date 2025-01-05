/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:13:26 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/05 14:51:18 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int handle_redirect_mode(t_instruction_data *instruction_data, char ***string)
{
	int in_or_out;

	in_or_out = 0;
	if(**string == '<' && *(*string + 1) == '<')
	{
		instruction_data->in_redirect_mode = 1;
		*string++;
	}
	else if(**string == '<')
		instruction_data->in_redirect_mode = 0;
	else
	{
		in_or_out = 1;
		if(**string == '>' && *(*string + 1) == '>')
		{
			instruction_data->out_redirect_mode = 1;
			*string++;
		}
		else if(**string == '>')
			instruction_data->out_redirect_mode = 0;
	}
	*string++;
	return (in_or_out);
}

static int get_size_of_redirect_param(char *string)
{
	char *tmp;
	int size;
	int is_in_single_quote;
	int is_in_double_quote;

	size = 0;
	tmp = string;
	while(*tmp && (!ft_isspace(*tmp) || !is_in_single_quote || !is_in_double_quote))
	{
		if (!toggle_quotes(&is_in_single_quote, &is_in_double_quote, *tmp))
			size++;
		tmp++;
	}
	if(!*tmp && (is_in_single_quote || is_in_double_quote))
		return (ft_strlen(string));
	return (size);
}

void set_redirect_data(t_instruction_data *instruction_data, char *string)
{
	char *tmp;
	char *param;
	int param_index;
	int is_in_single_quote;
	int is_in_double_quote;
	int in_or_out;

	is_in_single_quote = 0;
	is_in_double_quote = 0;
	in_or_out = handle_redirect_mode(instruction_data, &string);
	tmp = string;
	while(ft_isspace(*tmp))
		tmp++;
	param = malloc(sizeof(char) * (get_size_of_redirect_param(string) + 1));
	param_index = 0;
	while(*tmp && (!ft_isspace(*tmp) || !is_in_single_quote || !is_in_double_quote))
	{
		if (!toggle_quotes(&is_in_single_quote, &is_in_double_quote, *tmp))
		{
			param[param_index] = *tmp;
			param_index++;
		}
		tmp++;
	}
	if(!*tmp && (is_in_single_quote || is_in_double_quote))
		ft_strlcpy(param, string, ft_strlen(string));
	if(in_or_out == 0)
		instruction_data->in_redirect_param = param;
	else if(in_or_out == 1)
		instruction_data->out_redirect_param = param;
}
