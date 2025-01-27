/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:41:23 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 10:48:11 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char* ft_value_joiner(char *original, char *new_val)
{
	int		i;
	int 
	char	*new_value;

	i = 0;
	new_value = malloc(sizeof(char) * ft_strlen(original)
				+ ft_strlen(new_val) + 1);
	if (!new_value)
		return (NULL);
	while (original[i])
	{
		new_value[i] = original[i];
		i++;
	}
	i = 0;
}

int	append_env_var(char *var_name, char *value, char **environ)
{
	int		i;
	char	*new_var;

	i = 0;
	while (environ[i])
	{
		if (is_same_env_var(var_name, environ[i]))
			break ;
		else
			i++;
	}
	if (!value)
		return (0);
	new_var = ft_value_joiner(environ[i], value);
	if (!new_var)
		return (perror("malloc"), -1);
	free(environ[i]);
	environ[i] = new_var;
	set_minishell_env(environ);
	return (0);
}