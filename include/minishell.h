/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 03:08:14 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
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
void	builtin_echo(char **args);
void	builtin_env(t_list *vars);
void	builtin_export(t_list **vars, char *content);
void	builtin_pwd(t_list *vars);
void	builtin_unset(t_list **vars, char *content);

/* Execution */
char	*build_cmd_path(t_list *vars, char *cmd);

/* Validation */
int		is_valid_key(char *var_content);

/* Variables */
void	var_clear(void *var_content);
t_var	*var_create(char *var_content, int exported);
t_var	*var_get(t_list *vars, char *var_key);
char	*var_get_value(t_list *vars, char *var_key);
void	var_set(t_list **vars, char *var_content, int exported);
void	var_unset(t_list **vars, char *var_key);
void	var_update(t_list **vars, t_var *var);

#endif