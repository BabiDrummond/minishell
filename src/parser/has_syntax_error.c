/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_syntax_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:39 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/19 22:23:38 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	print_error(void)
{
	printf("Syntax Error: two consecutive operators\n");
	gc_exit();
	return (1);
}

static int	is_ast_operator(t_token *token)
{
	char	*operator;

	if (token->is_operator)
	{
		operator = token->link.content;
		if (ft_strcmp(operator, "&&") == 0
			|| ft_strcmp(operator, "||") == 0
			|| ft_strcmp(operator, "|") == 0)
			return (TRUE);
	}
	return (FALSE);
}

int	has_syntax_error(t_head *tokens)
{
	t_token	*current_token;

	if (tokens == NULL)
		return (print_error());
	current_token = (t_token *)tokens->first;
	if (is_ast_operator(current_token))
		return (print_error());
	while (current_token)
	{
		if (is_ast_operator(current_token) && (current_token->link.next == NULL
				|| is_ast_operator(((t_token *)current_token->link.next))))
			return (print_error());
		current_token = (t_token *)current_token->link.next;
	}
	return (FALSE);
}
