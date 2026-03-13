/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:14:43 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/13 20:16:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "lexer.h"
# include "../libft/include/libft.h"

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

t_ast	*parse(t_head *tokens, char **operators);
void	print_ast(t_ast *node, int depth);
int		has_syntax_error(t_head *tokens);

#endif
