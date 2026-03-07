/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:19:10 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 02:00:12 by bmoreira         ###   ########.fr       */
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

typedef struct s_var
{
	char	*key;
	char	*value;
	int		exported;
}	t_var;

typedef struct s_shell
{
	t_list	*vars;
	char	**args;
}	t_shell;

/* Built-ins */
int		builtin_cd(t_list **vars, char **args);
int		builtin_echo(char **args);
int		builtin_env(t_list *vars);
int		builtin_export(t_list **vars, char **args);
int		builtin_pwd(t_list *vars);
int		builtin_unset(t_list **vars, char **args);

/* Execution */
int		execute(t_ast *node, char **envp);
char	*find_cmd_path(t_list *vars, char *cmd);
char	*join_token_parts(t_token *token);

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