/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 01:26:59 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 01:43:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

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
	t_shell	*ctx;

	ctx = get_shell_ctx();
	if (g_signal == SIGINT)
	{
		rl_done = 1;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		exit_status(ctx, CTRL_C);
	}
	return (EXIT_SUCCESS);
}
