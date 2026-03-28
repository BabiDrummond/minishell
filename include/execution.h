/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:19:10 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 02:47:23 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include "parser.h"
# include <termios.h>
# include "../libft/include/libft.h"
# include "shell.h"

typedef struct s_var
{
	char	*key;
	char	*value;
	int		exported;
}	t_var;


/* Built-ins */
int		builtin_cd(t_list **vars, char **argv);
int		builtin_echo(char **argv);
int		builtin_env(t_list *vars, char **argv);
int		builtin_exit(t_shell *shell, char **argv);
int		builtin_export(t_list **vars, char **argv);
int		builtin_pwd(t_list *vars);
int		builtin_unset(t_list **vars, char **argv);
int		exit_status(t_shell *ctx, int exit_code, int should_exit);

/* Execution */
int		execute(t_shell *shell, t_ast *node, int is_child);
int		execute_cmd(t_shell *ctx, t_exec_node *node, int is_child);
int		execute_builtin_cmd(t_shell *ctx, char **argv);
int		execute_external_cmd(t_shell *ctx, char **argv, int is_child);
int		execute_operator(t_shell *ctx, t_ast *ast, t_exec_node *node,
			int is_child);
int		process_redirects(t_shell *ctx, t_list *redirs, int is_child);
void	restore_fds(t_shell *ctx, int is_child);
char	**build_argv(t_list *args);
char	*find_cmd_path(t_list *vars, char *cmd);

/* Utils */
t_list	*envp_to_lst(char **envp);
char	**lst_to_envp(t_list *vars);
char	*extract_key(char *var_content);
char	*extract_value(char *var_content);
int		is_valid_key(char *var_content);

/* Variables */
t_var	*var_create(char *key, char *value, int exported);
t_var	*var_get(t_list *vars, char *key);
char	*var_get_value(t_list *vars, char *key);
int		var_set(t_list **vars, char *key, char *value, int exported);
void	var_unset(t_list **vars, char *key);
void	var_update(t_list **vars, t_var *var);

#endif