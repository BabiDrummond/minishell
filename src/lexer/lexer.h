/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:40:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 20:35:43 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "listft.h"
# include "stringft.h"
# include "gcft.h"

typedef enum e_char_type	t_char_type;
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
	int		stdin_fd;
}	t_token;


char	**initialize_operators(void);
t_list		*tokenize(char *prompt, char **operators);
void		print_tokens(t_list *tokens);
#endif