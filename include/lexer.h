/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:40:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 22:12:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/include/libft.h"

typedef enum e_char_type
{
	IS_NORMAL,
	IS_NULL,
	IS_SINGLE_QUOTE,
	IS_DOUBLE_QUOTE,
	IS_OPERATOR,
	IS_WHITESPACE
}	t_char_type;

typedef enum e_quote_state
{
	QUOTE_NONE,
	QUOTE_SINGLE,
	QUOTE_DOUBLE
}	t_quote_state;

typedef struct s_word
{
	t_node			link;
	t_quote_state	quote_state;
}	t_word;

typedef struct s_token
{
	t_node	link;
	int		is_operator;
}	t_token;

char		**init_lexer_operators(void);
t_head		*tokenize(char *prompt, char **operators);
t_char_type	get_char_type(const char *str, char **operators);
t_word		*create_word(const char *value, int length,
				t_quote_state quote_state);
t_token		*create_token(void *content, int is_operator);
void		**get_next_token(char *str, char **operators);
void		**create_token_result(void *str, void *token_value);
void		print_tokens(t_head *tokens);
void		syntax_error(void);

#endif