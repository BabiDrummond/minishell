/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:19:10 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 01:28:33 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include "../libft/include/libft.h"
# include "parser.h"
# include "expansion.h"
# include "variables.h"
# include "utils.h"

/* Built-ins */
int		builtin_cd(t_list **vars, char **argv);
int		builtin_echo(char **argv);
int		builtin_env(t_list *vars, char **argv);
int		builtin_exit(t_shell *shell, char **argv);
int		builtin_export(t_list **vars, char **argv);
int		builtin_pwd(t_list *vars);
int		builtin_unset(t_list **vars, char **argv);
int		exit_status(t_shell *ctx, int exit_code);

/* Execution */
int		execute(t_shell *shell, t_ast *node, int is_child);
int		execute_cmd(t_shell *ctx, t_exec_node *node, int is_child);
int		execute_builtin_cmd(t_shell *ctx, char **argv);
int		execute_external_cmd(t_shell *ctx, char **argv, int is_child);
int		execute_operator(t_shell *ctx, t_ast *ast, t_exec_node *node,
			int is_child);
int		process_redirects(t_shell *ctx, t_list *redirs, int is_child);
void	restore_fds(t_shell *ctx, int is_child);
char	*find_cmd_path(t_list *vars, char *cmd);

#endif