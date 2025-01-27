/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicbaecher <loicbaecher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:22 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 19:13:15 by loicbaecher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	ft_echo(int new_line_flag, char *str, int last);
int		change_directory(char *str);
int		get_pwd(void);
int		export_var(char *var_name, char *value, char **environ);
int		display_all_env(char **environ);
int		display_all_export(char **environ);
char	**env_bubble_sort(char **new_env);
char	**malloc_copy_env(char **envp);
char	**malloc_add_var(char **envp, int *i);
int		is_same_env_var(char *var_name, char *environ_line);
char	*fill_env_str(char *new_var, char *var_name, char *val);
int		remove_var(char *var_name, char **envp);
int		check_existing_var(char *var_name, char **envp);
void	free_env(char **new_env);
char	**create_new_env(char **old_env);
char	**malloc_copy_less(char **envp, int not_included);
int		find_env_index(char **envp, char *var_name);
int		echo_sorter(char **args);
int		cd_sorter(char	**args);
int		export_sorter(char **args);
int		unset_sorter(char **args);
int		exit_w_status(t_list *tokens, char **args);
char	*my_get_env(char *var_name);
int		env_sorter(char **args);
int		new_env_var_str(char *var, char *val, char **new_var);
int		new_env_var_empty(char *var, char **new_var);
void	fill_env_str_empty(char *line, char **name_str);
int		check_exportable(char *var);
int		append_plus_env_var(char *var, char *val, char **environ);
int		add_plus_env_var(char *var, char *val, char **environ);
int		check_plus_existing_var(char *var_name, char **environ);
void	actual_exit(int status, t_list *tokens);

#endif