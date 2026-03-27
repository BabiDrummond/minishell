/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:35:35 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 01:54:07 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node_type	get_node_type(t_token *token)
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

t_exec_node	*new_exec_node(t_node_type type, t_list *redirs, t_list *args)
{
	t_exec_node	*exec_node;

	exec_node = ft_calloc(1, sizeof(t_exec_node));
	exec_node->type = type;
	exec_node->redirs = redirs;
	exec_node->args = args;
	return (exec_node);
}

t_exec_node	*build_ast_node(t_token *token)
{
	t_exec_node	*exec_node;
	t_redir		*redir;

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
			lst_add_back(&exec_node->args, lst_new(token->link.content));
		token = (t_token *)token->link.next;
	}
	return (new_exec_node(NODE_CMD, exec_node->redirs, exec_node->args));
}
