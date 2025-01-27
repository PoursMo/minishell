/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_plus_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:02:56 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 17:13:53 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_same_plus_env_var(char *var_name, char *environ_line)
{
	int	y;

	y = 0;
	while (environ_line[y] != '=' && var_name[y] != '+')
	{
		if (environ_line[y] != var_name[y])
			return (0);
		y++;
	}
	if ((environ_line[y] == '=' && var_name[y] == '+')
		|| (environ_line[y] == '\0' && var_name[y] == '+'))
		return (1);
	return (0);
}

int	check_plus_existing_var(char *var_name, char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (is_same_plus_env_var(var_name, environ[i]))
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_app_plus_env_str(char *new_var, char *old_line, char *val)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (old_line[i])
		new_var[c++] = old_line[i++];
	i = 0;
	while (val[i])
		new_var[c++] = val[i++];
	new_var[c] = '\0';
	return (new_var);
}

int	append_plus_env_var(char *var, char *val, char **environ)
{
	int		i;
	char	*new_var;

	i = 0;
	while (environ[i])
	{
		if (is_same_plus_env_var(var, environ[i]))
			break ;
		else
			i++;
	}
	if (!val)
		return (0);
	new_var = malloc(sizeof(char) * (ft_strlen(environ[i])
				+ ft_strlen(val) + 1));
	if (!new_var)
		return (perror("malloc"), 1);
	new_var = fill_app_plus_env_str(new_var, environ[i], val);
	free(environ[i]);
	environ[i] = new_var;
	set_minishell_env(environ);
	return (0);
}
