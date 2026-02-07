/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/07 18:52:57 by bmoreira         ###   ########.fr       */
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
	char	**envp;
	char	**path;
	char	*cmd_path;
	char	**cmd_args;
}	t_shell;

char	**get_env_path(char **envp);
char	*build_cmd_path(char **path, char *cmd);

#endif