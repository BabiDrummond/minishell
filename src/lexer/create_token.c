/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:43:59 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/19 17:38:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*create_token(void *content, int is_operator)
{
	t_token	*new_token;

	new_token = (t_token *) ft_calloc(1, sizeof(t_token));
	new_token->link.list = NULL;
	new_token->link.next = NULL;
	new_token->link.prev = NULL;
	new_token->link.content = content;
	new_token->is_operator = is_operator;
	new_token->stdin_fd = -1;
	return (new_token);
}
