/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 01:26:59 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 01:32:10 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "minishell.h"

void		set_signals(void);
static void	sig_handler(int sig);
static int	sig_hook(void);

void	set_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	rl_event_hook = sig_hook;
}

static void	sig_handler(int sig)
{
	g_signal = sig;
}

static int	sig_hook(void)
{
	if (g_signal == SIGINT)
	{
		rl_done = 1;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return (EXIT_SUCCESS);
}
