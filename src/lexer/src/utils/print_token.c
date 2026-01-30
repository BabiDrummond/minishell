/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:55:53 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/29 20:56:03 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_private.h"
#include <stdio.h>

static char	*bool_to_str(int expandable)
{
	if (expandable)
		return ("true");
	return ("false");
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
		printf(operator_text, ((t_string *)token->link.content)->value);
	else
	{
		printf("Token: {type: 'WORD', parts: ");
		part = (t_word *)((t_list *)token->link.content)->first;
		printf("[");
		while (part)
		{
			printf("{ value: '%s', expandable: %s }%s",
				(char *)part->link.content,
				bool_to_str(part->expandable),
				coma_if_has_next((t_word *)part->link.next)
				);
			part = (t_word *)part->link.next;
		}
		printf("]}\n");
	}
	return (1);
}
