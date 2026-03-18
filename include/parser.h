/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:14:43 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/17 20:45:48 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "lexer.h"
# include "execution.h"
# include "minishell.h"
# include "../libft/include/libft.h"

t_ast	    *parse(t_head *tokens, char **operators);
char	    **init_ast_operators(void);
void	    print_ast(t_ast *node, int depth);
int         has_syntax_error(t_head *tokens);
t_node_type	get_node_type(t_token *token);
t_exec_node	*new_exec_node(t_node_type type, t_list *redirs, t_list *argv);
t_exec_node *build_ast_node(t_token *token);

#endif
