/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:22 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/21 10:21:34 by lbaecher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	ft_echo(int new_line_flag, char *str);
void	change_directory(char	*str);
int		get_pwd(void);
void	export_var(char	*var_name, char *value, char ***envp);
void	display_all_env(char **envp);
char	**env_bubble_sort(char **new_env);
char	**malloc_copy_env(char **envp);
char	**malloc_add_var(char **envp, int *i);
int		is_same_env_var(char *var_name, char *environ_line);
char	*fill_env_str(char *new_var, char *var_name, char *val);
int		remove_var(char *var_name, char ***envp);
int		check_existing_var(char *var_name, char **envp);
void	free_env(char ***new_env);
char	**create_new_env(char **old_env);
char	**malloc_copy_less(char **envp, int not_included);
int		find_index(char **envp, char *var_name);

#endif