/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:40:28 by aloubry           #+#    #+#             */
/*   Updated: 2025/01/28 14:08:48 by aloubry          ###   ########.fr       */
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
# include <signal.h>

# include "libft.h"
# include "history.h"
# include "signals.h"
# include "builtins.h"
# include "parsing.h"
# include "utils.h"
# include "execution.h"

# define PROMPT "\033[1;33mminishell$ \033[0;0m"

#endif