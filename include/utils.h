/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 01:59:26 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../libft/include/libft.h"
# include "variables.h"

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
	int				stdin_backup;
	int				stdout_backup;
}	t_shell;

t_shell	*get_shell_ctx(void);
t_list	*envp_to_lst(char **envp);
char	**lst_to_envp(t_list *vars);
int		get_trimmed_length(char *str);
int		print_error(char *error_message, int error_code);
int		print_syntax_error(char *error_message);

#endif