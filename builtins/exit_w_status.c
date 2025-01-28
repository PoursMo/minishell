/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_w_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:44:52 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/28 09:28:51 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long	ft_atoi_long(const char *nptr)
{
	long	mult;
	long	num;

	mult = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			mult = -1;
		nptr++;
	}
	num = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (num * mult);
}

void	actual_exit(int status, t_list *tokens)
{
	clear_history();
	free_env(get_minishell_env());
	free(get_minishell_env());
	if (tokens)
		ft_lstclear(&tokens, free);
	exit(status);
}

static int	ft_is_all_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (!ft_isdigit(str[i]))
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !((str[i] >= 9 && str[i] <= 13)
				|| !(str[i] == 32)))
			return (0);
		i++;
	}
	return (1);
}

static int	check_long_overflow(char *nb)
{
	int	sign;

	sign = 1;
	if (*nb == '-')
	{
		nb++;
		sign = -1;
	}
	if (ft_strlen(nb) > 19)
		return (1);
	if (ft_strlen(nb) == 19)
	{
		if (sign == 1 && ft_strncmp(nb, "9223372036854775807", 19) > 0)
			return (1);
		if (sign == -1 && ft_strncmp(nb, "9223372036854775808", 19) > 0)
			return (1);
	}
	return (0);
}

int	exit_w_status(t_list *tokens, char **args)
{
	int		i;
	long	store;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		return (free(args), actual_exit(0, tokens), 0);
	if (i == 2)
	{
		if (!ft_is_all_num(args[1]))
		{
			printf("exit: numeric argument required\n");
			return (free(args), actual_exit(2, tokens), 2);
		}
		else if (check_long_overflow(args[1]))
			return (printf("exit: numeric argument required\n"), 2);
		else
		{
			store = ft_atoi_long(args[1]);
			return (free(args), actual_exit(store & 0xff, tokens), 0);
		}
	}
	printf("exit: too many arguments\n");
	return (free(args), actual_exit(2, tokens), 2);
}
