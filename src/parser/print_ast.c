/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:07:03 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/14 03:37:35 by bcosta-b         ###   ########.fr       */
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


typedef struct s_redir
{
	char *symbol;
	t_token *target;
} t_redir;

typedef struct s_command // t_exec_node
{
	t_node_type type;
	t_list *redirs;
	t_list *argv;
} t_command;


static t_command *get_redir(t_token *token)
{
	(void) token;

	t_command *command = calloc(1, sizeof(t_command));
	while (token)
	{
		

		if(token->is_operator)
		{

			t_redir *redir = calloc(1, sizeof(t_redir));
			redir->symbol = token->link.content;

			t_token *target = (t_token*)token->link.next;
			if(!target)
				printf("wolvesshell: parse error near #####");
			
			redir->target = target;

			lst_add_back(&command->redirs, lst_new(redir));

			token = target;
	
		}
		else {

			lst_add_back(&command->argv, lst_new(token->link.content));
		}
		token = (t_token*)token->link.next;
	}
	return command;
}

static void print_argv(t_command *command)
{
	if(!command)
		return ;

	t_list *arg = command->argv;

	while(arg)
	{

		t_list *part = (t_list*)((t_head*)arg->content)->first;
		while(part)
		{
			printf("%s, ",(char*) part->content);
			part = part->next;
		}
		arg = arg->next;
	}
}
static void print_redirs(t_exec_node *command)
{
	if(!command)
		return ;

	t_list *node = command->redirs;

	while(node)
	{

		t_redir *redir = (t_redir*)node->content;
		printf("[%s, ", redir->symbol);
		
		t_token *target = redir->target;
		t_head *parts = (t_head*)target->link.content;
		t_word *word = (t_word*)parts->first;
		while(word)
		{
			printf("%s, ", (char*)word->link.content);
			word = (t_word*)word->link.next;
		}
		printf("], ");
		
		node = node->next;
	}
}

static void	print_ast_cmd(t_ast *node, int depth)
{
	print_ast_indent(depth);
	printf("{\n");
	print_ast_indent(depth + 1);
	printf("\"type\": \"CMD\",\n");
	print_ast_indent(depth + 1);
	t_command *command = get_redir(node->value);
	printf("\"redirs\": [");
	print_redirs(command);
	printf("]\n");
	print_ast_indent(depth + 1);
	printf("\"argv\": [");
	print_argv(command);
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
