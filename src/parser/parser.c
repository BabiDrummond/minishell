/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:24:36 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/13 19:58:57 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_ast	build_exec_node(t_head *tokens)
{
	t_token	*current_token;

	current_token = (t_token *)tokens->first;
	while (current_token)
	{
		
		current_token = (t_token *)current_token->link.next;
	}
}

t_ast	*parse(t_head *tokens, char **operators)
{
	t_token	*current_token;
	char	**operator;
	int i;

	if (has_syntax_error(tokens))
		return (NULL);
	operator = operators;
	i = 0;
	while (*operator && i < 3)
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
		i++;
	}
	return (ast_new(tokens->first));
}

// percorrer lista
// se encontrar operador (&& || pipe)
// dividir lista em 2 (antes e depois do operador)
// fazer isso recursivamente até não achar mais operadores
// ao chegar na folha (não tiver mais operadores), analisar folha e coletar redirs
// se redir, pegar redir e proximo argumento e colocar na lista de redirs
// colocar o resto no argv
// criar nó com TYPE, lista de redirs, e lista de argv
