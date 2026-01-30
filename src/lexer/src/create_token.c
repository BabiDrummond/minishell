/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:43:59 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 12:43:37 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_private.h"

t_token	*create_token(void *content, int is_operator)
{
	t_token	*new_token;

	new_token = (t_token *) ft_malloc(sizeof(t_token));
	new_token->link.list = NULL;
	new_token->link.next = NULL;
	new_token->link.prev = NULL;
	new_token->link.content = content;
	new_token->is_operator = is_operator;
	return (new_token);
}
