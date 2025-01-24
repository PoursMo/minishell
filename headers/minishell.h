/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaecher <lbaecher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:40:28 by aloubry           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/06 18:09:43 by lbaecher         ###   ########.fr       */
=======
/*   Updated: 2025/01/09 17:47:47 by lbaecher         ###   ########.fr       */
>>>>>>> origin/main
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

# include "libft.h"
<<<<<<< HEAD
# include "history.h"
=======
# include "builtins.h"
# include "parsing.h"
# include "utils.h"
# include "execution.h"
>>>>>>> origin/main

#endif