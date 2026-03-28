/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:07:03 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 22:12:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_ast_indent(int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		printf("  ");
		i++;
	}
}

static char	*get_operator_symbol(t_node_type node_type)
{
	if (node_type == NODE_AND)
		return ("&&");
	else if (node_type == NODE_OR)
		return ("||");
	else if (node_type == NODE_PIPE)
		return ("|");
	return ("");
}

static void	print_ast_operator(t_ast *node, int depth)
{
	print_ast_indent(depth);
	printf("Execution AST: {\n");
	print_ast_indent(depth + 1);
	printf("\"type\": \"OPERATOR\",\n");
	print_ast_indent(depth + 1);
	printf("\"symbol\": %s,\n",
		get_operator_symbol(((t_exec_node *)node->value)->type));
	print_ast_indent(depth + 1);
	printf("\"left\": ");
	print_ast(node->left, depth + 1);
	printf(",\n");
	print_ast_indent(depth + 1);
	printf("\"right\": ");
	print_ast(node->right, depth + 1);
	printf("\n");
	print_ast_indent(depth);
	printf("}");
}

static void	print_argv(t_exec_node *exec_node)
{
	t_list	*arg;
	t_list	*part;

	if (!exec_node)
		return ;
	arg = exec_node->args;
	while (arg)
	{
		part = (t_list *)((t_head *)arg->content)->first;
		while (part)
		{
			printf("%s, ", (char *) part->content);
			part = part->next;
		}
		arg = arg->next;
	}
}

static void	print_redirs(t_exec_node *exec_node)
{
	t_list	*node;
	t_redir	*redir;
	t_word	*word;

	if (!exec_node)
		return ;
	node = exec_node->redirs;
	while (node)
	{
		redir = (t_redir *) node->content;
		printf("[%s, ", redir->type);
		word = redir->target;
		while (word)
		{
			printf("%s, ", (char *) word->link.content);
			word = (t_word *) word->link.next;
		}
		printf("], ");
		node = node->next;
	}
}

static void	print_ast_cmd(t_ast *node, int depth)
{
	t_exec_node	*exec_node;

	exec_node = (t_exec_node *) node->value;
	print_ast_indent(depth);
	printf("{\n");
	print_ast_indent(depth + 1);
	printf("\"type\": \"CMD\",\n");
	print_ast_indent(depth + 1);
	printf("\"redirs\": [");
	print_redirs(exec_node);
	printf("]\n");
	print_ast_indent(depth + 1);
	printf("\"argv\": [");
	print_argv(exec_node);
	printf("]\n");
	print_ast_indent(depth);
	printf("}");
}

void	print_ast(t_ast *node, int depth)
{
	if (!node)
	{
		printf("null");
		return ;
	}
	if (((t_exec_node *)node->value)->type == NODE_CMD)
		print_ast_cmd(node, depth);
	else
		print_ast_operator(node, depth);
	if (!depth)
		printf("\n");
}
