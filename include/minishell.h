/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:10:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/17 20:45:30 by bmoreira         ###   ########.fr       */
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
# include "execution.h"
# include "heredoc.h"
# include "lexer.h"
# include "parser.h"

typedef enum e_node_type
{
	NODE_AND,
	NODE_OR,
	NODE_PIPE,
	NODE_CMD
}	t_node_type;

typedef enum e_redir_type
{
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC
}   t_redir_type;

typedef struct s_redir
{
	char	*type;
	t_word	*target;
}	t_redir;

typedef struct s_exec_node
{
	t_node_type type;
	t_list		*redirs;
	t_list		*argv;
}	t_exec_node;

#endif