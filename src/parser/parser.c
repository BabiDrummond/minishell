/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:24:36 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 15:36:10 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stringft.h"
#include "gcft.h"
#include <stdio.h>

static void	set_right(t_list *right, t_token *current_token, t_list *tokens)
{
	right->first = current_token->link.next;
	right->last = tokens->last;
	if (current_token->link.next)
		current_token->link.next->prev = NULL;
}

static void	set_left(t_list *left, t_token *current_token, t_list *tokens)
{
	left->first = tokens->first;
	left->last = current_token->link.prev;
	if (current_token->link.prev)
		current_token->link.prev->next = NULL;
}

static t_ast	*parse_operators(t_token *token,
	char **operators, t_list *tokens)
{
	t_ast		*node;
	t_list		right;
	t_list		left;

	right.first = NULL;
	right.last = NULL;
	left.first = NULL;
	left.last = NULL;
	node = ast_new(token);
	set_left(&left, token, tokens);
	set_right(&right, token, tokens);
	if (left.first)
		node->left = parse(&left, operators);
	if (right.first)
		node->right = parse(&right, operators);
	return (node);
}

static int	operator_is_equal(t_token *token, char *operator)
{
	return (token->is_operator
		&& ft_strcmp(((char*)token->link.content),
			operator) == 0);
}

t_ast	*parse(t_list *tokens, char **operators)
{
	char	**operator;
	t_token		*current_token;

	if (has_syntax_error(tokens))
		return (NULL);
	operator = operators;
	while (*operator)
	{
		current_token = (t_token *)tokens->last;
		while (current_token)
		{
			if (operator_is_equal(current_token, *operator))
				return (parse_operators(
						current_token,
						operators,
						tokens
					));
			current_token = (t_token *)current_token->link.prev;
		}
		operator++;
	}
	return (ast_new(tokens->first));
}
