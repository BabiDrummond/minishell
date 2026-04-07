/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:39 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/28 23:11:36 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			parser_syntax_error(t_head *tokens);
static int	is_ast_operator(t_token *token);

int	parser_syntax_error(t_head *tokens)
{
	t_token	*current_token;

	current_token = (t_token *)tokens->first;
	if (is_ast_operator(current_token))
		return (print_syntax_error(current_token->link.content));
	while (current_token)
	{
		if (is_ast_operator(current_token) && (current_token->link.next == NULL
				|| is_ast_operator(((t_token *)current_token->link.next))))
			return (print_syntax_error(current_token->link.content));
		current_token = (t_token *)current_token->link.next;
	}
	return (FALSE);
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
