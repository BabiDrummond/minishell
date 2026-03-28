/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 23:13:03 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int			execute_operator(
				t_shell *ctx, t_ast *ast, t_exec_node *node, int is_child);
static int	execute_and(t_shell *ctx, t_ast *ast, int is_child);
static int	execute_or(t_shell *ctx, t_ast *ast, int is_child);
static int	execute_pipe(t_shell *ctx, t_ast *ast, int is_child);
static void	pipe_children(t_shell *ctx, t_ast *ast, int pipefd[2], int pid[2]);

int	execute_operator(t_shell *ctx, t_ast *ast, t_exec_node *node, int is_child)
{
	if (node->type == NODE_AND)
		ctx->exit_status = execute_and(ctx, ast, is_child);
	else if (node->type == NODE_OR)
		ctx->exit_status = execute_or(ctx, ast, is_child);
	else if (node->type == NODE_PIPE)
		ctx->exit_status = execute_pipe(ctx, ast, is_child);
	return (ctx->exit_status);
}

static int	execute_and(t_shell *ctx, t_ast *ast, int is_child)
{
	ctx->exit_status = execute(ctx, ast->left, is_child);
	if (ctx->exit_status == EXIT_SUCCESS)
		ctx->exit_status = execute(ctx, ast->right, is_child);
	return (ctx->exit_status);
}

static int	execute_or(t_shell *ctx, t_ast *ast, int is_child)
{
	ctx->exit_status = execute(ctx, ast->left, is_child);
	if (ctx->exit_status != EXIT_SUCCESS)
		ctx->exit_status = execute(ctx, ast->right, is_child);
	return (ctx->exit_status);
}

static int	execute_pipe(t_shell *ctx, t_ast *ast, int is_child)
{
	int	pipefd[2];
	int	pid[2];
	int	status;

	pipe(pipefd);
	pipe_children(ctx, ast, pipefd, pid);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}

static void	pipe_children(t_shell *ctx, t_ast *ast, int pipefd[2], int pid[2])
{
	pid[0] = fork();
	if (pid[0] < 0)
		exit(EXIT_FAILURE);
	else if (pid[0] == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		ctx->exit_status = execute(ctx, ast->left, TRUE);
		exit(ctx->exit_status);
	}
	pid[1] = fork();
	if (pid[1] < 0)
		exit(EXIT_FAILURE);
	else if (pid[1] == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		ctx->exit_status = execute(ctx, ast->right, TRUE);
		exit(ctx->exit_status);
	}
}
