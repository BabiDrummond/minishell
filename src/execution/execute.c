/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/09 16:45:09 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_operator(t_ast *node, t_token *token)
{
	(void) node;
	(void) token;
	return (0);
	// char	*operator;

	// operator = (char *)token->link.content;
	// if (ft_strcmp(operator, "|") == 0)
	// 	return (execute_pipe(node->left, node->right));
	// else if (ft_strcmp(operator, "&&") == 0)
	// 	return (execute_and(node->left, node->right));
	// else if (ft_strcmp(operator, "||") == 0)
	// 	return (execute_or(node->left, node->right));
	// else if (ft_strcmp(operator, "<") == 0)
	// 	return (execute_redir_in(node->left, node->right));
	// else if (ft_strcmp(operator, ">") == 0)
	// 	return (execute_redir_out(node->left, node->right));
	// else if (ft_strcmp(operator, ">>") == 0)
	// 	return (execute_redir_append(node->left, node->right));
}

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "unset") == 0
	)
		return (TRUE);
	return (FALSE);
}

int	execute_command(t_token *token, t_list *vars, int is_child)
{
	char	**argv;
	int		exit_status;

	argv = build_argv(token);
	if (is_builtin(argv[0]))
		exit_status = execute_builtin_cmd(vars, argv);
	else
		exit_status = execute_external_cmd(vars, argv, is_child);
	ft_split_free(argv);
	return (exit_status);
}

int	execute(t_ast *node, t_list *vars, int is_child)
{
	t_token	*token;

	if (!node)
		return (0);
	token = (t_token *)node->value;
	if (token && token->is_operator)
		return (execute_operator(node, token));
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
