/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:19:10 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/08 00:08:07 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "lexer.h"
# include "parser.h"
# include "../libft/include/libft.h"

typedef enum s_exit_status
{
	SUCCESS = 0,
	FAILURE = 1,
	SYNTAX_ERROR = 2,
	PERMISSION_DENIED = 126,
	CMD_NOT_FOUND = 127,
	CTRL_C = 130,
	CTRL_QUIT = 131
}	t_exit_status;

typedef struct s_var
{
	char	*key;
	char	*value;
	int		exported;
}	t_var;

typedef struct s_shell
{
	t_head			*tokens;
	t_list			*vars;
	t_ast			*ast;
	t_exit_status	exit_status;
}	t_shell;

// t_shell
// ast
// tokens?
// vars
// argv
// envp
// exit_status
// redirs

/* Built-ins */
int		builtin_cd(t_list **vars, char **args);
int		builtin_echo(char **args);
int		builtin_env(t_list *vars, char **args);
int		builtin_export(t_list **vars, char **args);
int		builtin_pwd(t_list *vars);
int		builtin_unset(t_list **vars, char **args);

/* Execution */
int		execute(t_ast *node, t_list *vars, int is_child);
int		execute_builtin_cmd(t_list *vars, char **argv);
int		execute_external_cmd(t_list *vars, char **argv, int is_child);
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