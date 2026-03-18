/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:24:36 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/17 21:42:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_right(t_head *right, t_token *current_token, t_head *tokens)
{
	right->first = current_token->link.next;
	right->last = tokens->last;
	if (current_token->link.next)
		current_token->link.next->prev = NULL;
}

static void	set_left(t_head *left, t_token *current_token, t_head *tokens)
{
	left->first = tokens->first;
	left->last = current_token->link.prev;
	if (current_token->link.prev)
		current_token->link.prev->next = NULL;
}

static t_ast	*parse_operators(t_token *token,
	char **operators, t_head *tokens)
{
	t_ast		*node;
	t_head		right;
	t_head		left;

	right.first = NULL;
	right.last = NULL;
	left.first = NULL;
	left.last = NULL;
	node = ast_new(new_exec_node(get_node_type(token), NULL, NULL));
	set_left(&left, token, tokens);
	set_right(&right, token, tokens);
	if (left.first)
		node->left = parse(&left, operators);
	if (right.first)
		node->right = parse(&right, operators);
	return (node);
}

t_ast	*parse(t_head *tokens, char **operators)
{
	t_token	*current_token;
	int		i;

	i = 0;
	if (has_syntax_error(tokens))
		return (NULL);
	while (operators[i])
	{
		current_token = (t_token *)tokens->last;
		while (current_token)
		{
			if (current_token->is_operator
				&& ft_strcmp((current_token->link.content), operators[i]) == 0)
				return (parse_operators(current_token, operators, tokens));
			current_token = (t_token *)current_token->link.prev;
		}
		i++;
	}
	return (ast_new(build_ast_node((t_token *)tokens->first)));
}
