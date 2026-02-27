/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_syntax_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:39 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 17:41:27 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int	print_error(void)
{
	printf("Syntax Error: two consecutive operators\n");
	gc_exit();
	return (1);
}

int	has_syntax_error(t_head *tokens)
{
	t_token	*current_token;

	if (tokens == NULL)
		return (print_error());
	current_token = (t_token *)tokens->first;
	if (current_token->is_operator)
		return (print_error());
	while (current_token)
	{
		if (current_token->is_operator
			&& (current_token->link.next == NULL
				|| ((t_token *)current_token->link.next)->is_operator))
			return (print_error());
		current_token = (t_token *)current_token->link.next;
	}
	return (0);
}
