/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 04:34:44 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/include/libft.h"

extern int	g_signal;

typedef enum s_exit_status
{
	SYNTAX_ERROR = 2,
	PERMISSION_DENIED = 126,
	CMD_NOT_FOUND = 127,
	CTRL_C = 130,
	CTRL_QUIT = 131
}	t_exit_status;

typedef struct s_shell
{
	pid_t			pid;
	t_list			*vars;
	t_exit_status	exit_status;
	int				should_exit;
	int				stdin_backup;
	int				stdout_backup;
}	t_shell;

t_shell	*get_shell_ctx(void);
int		print_syntax_error(char *token);
int		print_error(char *error_message, int error_code);



#endif