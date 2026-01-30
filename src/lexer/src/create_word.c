/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:45:02 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 12:43:29 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_private.h"

t_word	*create_word(const char *value, int length, int expandable)
{
	t_word	*new_word;

	new_word = (t_word *) ft_malloc(sizeof(t_word));
	new_word->link.list = NULL;
	new_word->link.next = NULL;
	new_word->link.prev = NULL;
	new_word->link.content = ft_strndup(value, length);
	new_word->link.list = NULL;
	new_word->expandable = expandable;
	return (new_word);
}
