/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 21:53:14 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/include/libft.h"
# include "heredoc.h"
# include "lexer.h"
# include "parser.h"

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
char	*build_cmd_path(t_list *vars, char *cmd);

/* Utils */
t_list	*envp_to_lst(char **envp);
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