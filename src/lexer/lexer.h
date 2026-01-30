/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:40:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:47:38 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "listft.h"
# include "stringft.h"
# include "gcft.h"

typedef enum e_char_type	t_char_type;
typedef struct s_word		t_word;
typedef struct s_token		t_token;

t_string	**initialize_operators(void);
t_list		*tokenize(char *prompt, t_string **operators);
void		print_tokens(t_list *tokens);
#endif