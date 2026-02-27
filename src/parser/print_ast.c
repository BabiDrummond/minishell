/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:07:03 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/02 19:56:06 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	print_ast_operator(t_ast *node, int depth)
{
	print_ast_indent(depth);
	printf("Execution AST: {\n");
	print_ast_indent(depth + 1);
	printf("\"type\": \"OPERATOR\",\n");
	print_ast_indent(depth + 1);
	printf("\"symbol\": %s,\n",
		((char *)((t_token *)node->value)->link.content));
	print_ast_indent(depth + 1);
	printf("\"stdin_fd\": %d,\n", ((t_token *)node->value)->stdin_fd);
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

static void	print_ast_cmd_argv(t_token *token)
{
	int		first_arg;
	t_word	*part;

	first_arg = 1;
	while (token)
	{
		part = (t_word *)((t_head *)token->link.content)->first;
		while (part)
		{
			if (!first_arg)
				printf(", ");
			printf("\"%s\"", (char *)part->link.content);
			first_arg = 0;
			part = (t_word *)part->link.next;
		}
		token = (t_token *)token->link.next;
	}
}

static void	print_ast_cmd(t_ast *node, int depth)
{
	print_ast_indent(depth);
	printf("{\n");
	print_ast_indent(depth + 1);
	printf("\"type\": \"CMD\",\n");
	print_ast_indent(depth + 1);
	printf("\"argv\": [");
	print_ast_cmd_argv(node->value);
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
	if (((t_token *)node->value)->is_operator)
		print_ast_operator(node, depth);
	else
		print_ast_cmd(node, depth);
	if (!depth)
		printf("\n");
}
