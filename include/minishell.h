/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/11 23:52:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/include/libft.h"

typedef struct s_shell
{
	t_list	*env;
	char	**cmd_args;
	char	*cmd_path;
}	t_shell;

char	**get_env_path(char **envp);
char	*build_cmd_path(t_shell *info, char *cmd);
char	*get_env_var(t_list *env, char *var_name);

/* Built-ins */
void	builtin_echo(t_shell *info);
void	builtin_env(t_list *env);
void	builtin_pwd(t_list *env);

#endif