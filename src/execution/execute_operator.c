/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/14 22:19:32 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	execute_and(t_shell *ctx, t_ast *left, t_ast *right, int is_child)
{
	ctx->exit_status = execute(ctx, left, is_child);
	if (ctx->exit_status == EXIT_SUCCESS)
		ctx->exit_status = execute(ctx, right, is_child);
	return (ctx->exit_status);
}

static int	execute_or(t_shell *ctx, t_ast *left, t_ast *right, int is_child)
{
	ctx->exit_status = execute(ctx, left, is_child);
	if (ctx->exit_status != EXIT_SUCCESS)
		ctx->exit_status = execute(ctx, right, is_child);
	return (ctx->exit_status);
}

// int	execute_pipe(t_shell *shell, t_ast *left, t_ast *right, int is_child)
// {
// }

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

int	execute_operator(t_shell *ctx, t_ast *ast, t_exec_node *node, int is_child)
{
	if (node->type == NODE_AND)
		ctx->exit_status = execute_and(ctx, ast->left, ast->right, is_child);
	else if (node->type == NODE_OR)
		ctx->exit_status = execute_or(ctx, ast->left, ast->right, is_child);
	// else if (node->type == NODE_PIPE)
	// 	ctx->exit_status = execute_pipe(ctx, ast->left,	ast->right, is_child);
	return (ctx->exit_status);
}
