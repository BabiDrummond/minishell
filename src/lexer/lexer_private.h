/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:40:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 20:32:23 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PRIVATE_H
# define LEXER_PRIVATE_H

# include "lexer.h"

enum e_char_type
{
	IS_NORMAL,
	IS_NULL,
	IS_SINGLE_QUOTE,
	IS_DOUBLE_QUOTE,
	IS_OPERATOR,
	IS_WHITESPACE
};

void		**create_token_result(void *str, void *token_value);
t_char_type	get_char_type(const char *str, t_string **operators);
t_word		*create_word(const char *value, int length, t_quote_state quote_state);
t_token		*create_token(void *content, int is_operator);
void		syntax_error(void);
void		**get_next_token(char *str, t_string **operators);
int			print_token( t_token *token );
#endif