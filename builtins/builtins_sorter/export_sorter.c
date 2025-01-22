/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:46:48 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/22 15:04:18 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	var_len(char *line, int *name_len, int *val_len)
{
	int	i;
	int	count;

	i = 0;
	while (line[i] != '=')
		i++;
	*name_len = i;
	count = 0;
	i++;
	while (line[i] != '\0')
	{
		i++;
		count++;
	}
	*val_len = i;
}

static void	fill_str(char *line, char **val_str, char **name_str)
{
	int	i_line;
	int	i;

	i = 0;
	i_line = 0;
	while (line[i_line] != '=')
	{
		(*name_str)[i] = line[i_line];
		i++;
		i_line++;
	}
	(*name_str)[i] = '\0';
	i = 0;
	i_line++;
	while (line[i_line] != '\0')
	{
		(*val_str)[i] = line[i_line];
		i++;
		i_line++;
	}
	(*val_str)[i] = '\0';
}

static void	export_splitter(char *line, char **new_env)
{
	int		len_val;
	int		len_name;
	char	*value;
	char	*name;

	var_len(line, &len_name, &len_val);
	value = malloc(sizeof(char) * (len_val + 1));
	name = malloc(sizeof(char) * (len_name + 1));
	if (!value || !name)
		return ;
	fill_str(line, &value, &name);
	export_var(name, value, new_env);
	free(value);
	free(name);
}

void	export_sorter(char **args, char **new_env)
{
	int		count;
	int		i;

	count = 0;
	while (args[count])
		count++;
	if (count < 1)
		return ;
	if (count == 1)
		return (display_all_export(new_env), (void) NULL);
	i = 1;
	export_splitter(args[i], new_env);
}
