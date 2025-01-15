/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:22 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/15 08:49:41 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	ft_echo(int new_line_flag, char *str);
void	change_directory(char	*str);
int		get_pwd(void);
void	export_var(char	*str);

#endif