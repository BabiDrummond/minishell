/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:55:53 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 20:37:47 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_private.h"
#include <stdio.h>

static char	*quote_state_to_str(t_quote_state quote_state)
{
	if (quote_state == QUOTE_NONE)
		return ("NONE");
	else if (quote_state == QUOTE_SINGLE)
		return ("SINGLE");
	else if (quote_state == QUOTE_DOUBLE)
		return ("DOUBLE");
	return ("UNKNOWN");
}

static char	*coma_if_has_next(t_word *word)
{
	if (word == NULL)
		return ("");
	return (", ");
}

int	print_token( t_token *token )
{
	const char	*operator_text = "Token: {type: 'OPERATOR', symbol: '%s' }\n";
	t_word		*part;

	if (!token)
		return (0);
	if (token->is_operator)
		printf(operator_text, ((char *)token->link.content));
	else
	{
		printf("Token: {type: 'WORD', parts: ");
		part = (t_word *)((t_head *)token->link.content)->first;
		printf("[");
		while (part)
		{
			printf("{ value: '%s', quote_state: %s }%s",
				(char *)part->link.content,
				quote_state_to_str(part->quote_state),
				coma_if_has_next((t_word *)part->link.next)
				);
			part = (t_word *)part->link.next;
		}
		printf("]}\n");
	}
	return (1);
}
