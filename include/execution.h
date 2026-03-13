/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:19:10 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/13 20:17:13 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "lexer.h"
# include "parser.h"
# include "../libft/include/libft.h"

typedef enum s_exit_status
{
	SYNTAX_ERROR = 2,
	PERMISSION_DENIED = 126,
	CMD_NOT_FOUND = 127,
	CTRL_C = 130,
	CTRL_QUIT = 131,
	INVALID_EXIT = 255
}	t_exit_status;

typedef struct s_var
{
	char	*key;
	char	*value;
	int		exported;
}	t_var;

typedef struct s_redir
{
	t_redir_type	type;
	char			*target;
} t_redir;

typedef struct s_exec_node
{
	t_node_type type;
	t_list		*redirs;
	t_list		*argv;
}	t_exec_node;

typedef struct s_shell
{
	pid_t			pid;
	t_list			*vars;
	t_exit_status	exit_status;
	int				stdin_backup;
	int				stdout_backup;
}	t_shell;

/* Built-ins */
int		builtin_cd(t_list **vars, char **argv);
int		builtin_echo(char **argv);
int		builtin_env(t_list *vars, char **argv);
int		builtin_exit(t_shell *shell, char **argv);
int		builtin_export(t_list **vars, char **argv);
int		builtin_pwd(t_list *vars);
int		builtin_unset(t_list **vars, char **argv);

/* Execution */
int		execute(t_shell *shell, t_ast *node, int is_child);
int		execute_command(t_shell *shell, t_token *token, int is_child);
int		execute_external_cmd(t_shell *shell, char **argv, int is_child);
int		execute_builtin_cmd(t_shell *shell, char **argv);
char	**build_argv(t_token *token);
char	*find_cmd_path(t_list *vars, char *cmd);

/* Utils */
t_list	*envp_to_lst(char **envp);
char	**lst_to_envp(t_list *vars);
char	*extract_key(char *var_content);
char	*extract_value(char *var_content);
int		is_valid_key(char *var_content);

/* Variables */
void	var_clear(void *var_content);
t_var	*var_create(char *key, char *value, int exported);
t_var	*var_get(t_list *vars, char *key);
char	*var_get_value(t_list *vars, char *key);
int		var_set(t_list **vars, char *key, char *value, int exported);
void	var_unset(t_list **vars, char *key);
void	var_update(t_list **vars, t_var *var);

#endif