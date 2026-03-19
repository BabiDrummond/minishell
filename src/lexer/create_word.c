/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:45:02 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/19 17:38:42 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_word	*create_word(const char *value, int length, t_quote_state quote_state)
{
	t_word	*new_word;

	new_word = (t_word *) ft_calloc(1, sizeof(t_word));
	new_word->link.list = NULL;
	new_word->link.next = NULL;
	new_word->link.prev = NULL;
	new_word->link.content = ft_strndup(value, length);
	new_word->link.list = NULL;
	new_word->quote_state = quote_state;
	return (new_word);
}
