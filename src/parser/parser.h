/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:14:43 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 20:09:56 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "astft.h"
# include "listft.h"
# include "stringft.h"
# include "lexer.h"

t_ast	*parse(t_list *tokens, t_string **operators);
void	print_ast(t_ast *node, int depth);

#endif
