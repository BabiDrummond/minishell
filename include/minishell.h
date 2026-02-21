/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 00:42:00 by bmoreira         ###   ########.fr       */
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
	char	**cmd_args;
	char	*cmd_path;
}	t_shell;

t_var	*var_create(char *var_content, int exported);
char	*var_get(t_list *vars, char *var_key);
void	var_set(t_list **vars, char *var_content);
void	var_update(t_list **vars, t_var *var);

char	*build_cmd_path(t_shell *info, char *cmd);

/* Built-ins */
void	builtin_echo(t_shell *info);
void	builtin_env(t_list *var_list);
void	builtin_pwd(t_list *env);

#endif