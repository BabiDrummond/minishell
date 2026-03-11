/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/10 21:10:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_and(t_ast *left, t_ast *right, t_list *vars, int is_child)
{
	int	exit_status;

	exit_status = execute(left, vars, is_child);
	if (exit_status == EXIT_SUCCESS)
		exit_status = execute(right, vars, is_child);
	return (exit_status);
}

int	execute_or(t_ast *left, t_ast *right, t_list *vars, int is_child)
{
	int	exit_status;

	exit_status = execute(left, vars, is_child);
	if (exit_status == EXIT_FAILURE)
		exit_status = execute(right, vars, is_child);
	return (exit_status);
}

int	execute_pipe(t_ast *left, t_ast *right, t_list *vars, int is_child)
{
	
}

int	execute_operator(t_ast *node, t_token *token, t_list *vars, int is_child)
{
	char	*operator;

	operator = (char *)token->link.content;
	if (ft_strcmp(operator, "|") == 0)
		return (execute_pipe(node->left, node->right, vars, is_child));
	else if (ft_strcmp(operator, "&&") == 0)
		return (execute_and(node->left, node->right, vars, is_child));
	else if (ft_strcmp(operator, "||") == 0)
		return (execute_or(node->left, node->right, vars, is_child));
	else if (ft_strcmp(operator, "<") == 0)
		return (execute_redir_in(node->left, node->right, vars, is_child));
	else if (ft_strcmp(operator, ">") == 0)
		return (execute_redir_out(node->left, node->right, vars, is_child));
	else if (ft_strcmp(operator, ">>") == 0)
		return (execute_redir_append(node->left, node->right, vars, is_child));
}

int	execute(t_ast *node, t_list *vars, int is_child)
{
	t_token	*token;

	if (!node)
		return (0);
	token = (t_token *)node->value;
	if (token && token->is_operator)
		return (execute_operator(node, token, vars, is_child));
	else
		return (execute_command(token, vars, is_child));
}

// todo PIPE
// add in_child to execute argv
// in_child default is false
// execute_pipe
// fork
// pass in_child as true
// execute_external_cmd receives in_child
// execute_external_cmd checks in_child
// if true -> execve directly (calls execute_in_parent)
// if false -> fork + execve (calls execute_in_child)
