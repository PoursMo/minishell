/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:24 by lbaecher          #+#    #+#             */
/*   Updated: 2025/01/27 18:24:34 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

//signal.c

void	make_sigactions(char mode,
			struct sigaction *sa_sigint, struct sigaction *sa_sigquit);

//signal2.c

int		set_sigquit(void);
int		set_signals(char mode);

#endif