/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:24:36 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/14 20:51:39 by bmoreira         ###   ########.fr       */
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

t_node_type get_node_type(t_token *token)
{
	if (token->is_operator)
	{
		if (ft_strcmp(token->link.content, "&&") == 0)
			return (NODE_AND);
		else if (ft_strcmp(token->link.content, "||") == 0)
			return (NODE_OR);
		else if (ft_strcmp(token->link.content, "|") == 0)
			return (NODE_PIPE);
	}
	return (NODE_CMD);
}

t_exec_node	*new_exec_node(t_node_type type, t_list *redirs, t_list *argv)
{
	t_exec_node *exec_node;

	exec_node = ft_calloc(1, sizeof(t_exec_node));
	if (!exec_node)
		return (NULL);
	exec_node->type = type;
	exec_node->redirs = redirs;
	exec_node->argv = argv;
	return (exec_node);
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

static int	operator_is_equal(t_token *token, char *operator)
{
	return (token->is_operator
		&& ft_strcmp(((char*)token->link.content),
			operator) == 0);
}

t_exec_node	*build_ast_node(t_token *token)
{
	t_exec_node *exec_node;
	t_redir *redir;

	exec_node = ft_calloc(1, sizeof(t_exec_node));
	while (token)
	{
		if (token->is_operator)
		{
			redir = ft_calloc(1, sizeof(t_redir));
			redir->type = token->link.content;
			if (!token->link.next)
				printf("minishell: parse error near %s\n", redir->type);
			redir->target = (t_word *)((t_head *)((t_token *)
							token->link.next)->link.content)->first;
			lst_add_back(&exec_node->redirs, lst_new(redir));
			token = (t_token *)token->link.next;
		}
		else
			lst_add_back(&exec_node->argv, lst_new(token->link.content));
		token = (t_token *)token->link.next;
	}
	return (new_exec_node(NODE_CMD, exec_node->redirs, exec_node->argv));
}

t_ast	*parse(t_head *tokens, char **operators)
{
	t_token	*current_token;
	int i;

	i = 0;
	if (has_syntax_error(tokens))
		return (NULL);
	while (operators[i] && i < 3)
	{
		current_token = (t_token *)tokens->last;
		while (current_token)
		{
			if (operator_is_equal(current_token, operators[i]))
				return (parse_operators(
						current_token,
						operators,
						tokens
					));
			current_token = (t_token *)current_token->link.prev;
		}
		i++;
	}
	return (ast_new(build_ast_node((t_token *)tokens->first)));
}

// percorrer lista
// se encontrar operador (&& || pipe)
// dividir lista em 2 (antes e depois do operador)
// fazer isso recursivamente até não achar mais operadores
// ao chegar na folha (não tiver mais operadores), analisar folha e coletar redirs
// se redir, pegar redir e proximo argumento e colocar na lista de redirs
// colocar o resto no argv
// criar nó com TYPE, lista de redirs, e lista de argv
