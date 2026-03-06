/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:14:43 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/06 19:46:07 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "lexer.h"
# include "../libft/include/libft.h"

t_ast	*parse(t_head *tokens, char **operators);
void	print_ast(t_ast *node, int depth);
int		has_syntax_error(t_head *tokens);

#endif
