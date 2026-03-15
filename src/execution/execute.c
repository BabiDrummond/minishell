/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/14 21:31:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_and(t_shell *ctx, t_ast *left, t_ast *right, int is_child)
{
	ctx->exit_status = execute(ctx, left, is_child);
	if (ctx->exit_status == EXIT_SUCCESS)
		ctx->exit_status = execute(ctx, right, is_child);
	return (ctx->exit_status);
}

int	execute_or(t_shell *ctx, t_ast *left, t_ast *right, int is_child)
{
	ctx->exit_status = execute(ctx, left, is_child);
	if (ctx->exit_status != EXIT_SUCCESS)
		ctx->exit_status = execute(ctx, right, is_child);
	return (ctx->exit_status);
}

int	get_stdin_fd(t_token *token)
{
	char	**argv;
	int		fd;
	int		i;

	i = 0;
	fd = -1;
	argv = build_argv(token);
	while (argv && argv[i])
	{
		if (fd != -1)	
			close(fd);
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			perror("fd");
			ft_split_free(argv);
			return (-1);
		}
		i++;
	}
	ft_split_free(argv);
	return (fd);
}

int	print_error_and_return(t_shell *ctx, char *error_msg, int exit_status)
{
	perror(error_msg);
	ctx->exit_status = exit_status;
	return (ctx->exit_status);
}

// int	execute_redir_in(t_shell *shell, t_ast *left, t_ast *right, int is_child)
// {
// 	t_token *token;
// 	int		fd;

// 	token = (t_token *) left->value;
// 	fd = get_stdin_fd(right->value);
// 	if (fd == -1)
// 		return (EXIT_FAILURE);
// 	if (token->is_operator)
// 		execute_redir_in(shell, left, token, is_child);
// 	dup2(fd, STDIN_FILENO);
// 	if (!token->is_operator)
// 		shell->exit_status = execute(shell, left, is_child);
// 	close(fd);
// 	dup2(shell->stdin_backup, STDIN_FILENO);
// 	return (shell->exit_status);
// }

// int	execute_redir_out(t_shell *shell, t_ast *left, t_ast *right, int is_child)
// {
// 	int		fd;

// 	fd = get_stdin_fd(right->value);
// 	if (fd == -1)
// 		return (EXIT_FAILURE);
// 	dup2(fd, STDIN_FILENO);
// 	shell->exit_status = execute(shell, left, is_child);
// 	close(fd);
// 	dup2(shell->stdin_backup, STDIN_FILENO);
// 	return (shell->exit_status);
// }

// int	execute_pipe(t_shell *shell, t_ast *left, t_ast *right, int is_child)
// {
	
// }

int	execute_operator(t_shell *ctx, t_ast *ast, t_exec_node *node, int is_child)
{
	if (node->type == NODE_AND)
		ctx->exit_status = execute_and(ctx, ast->left,
				ast->right, is_child);
	else if (node->type == NODE_OR)
		ctx->exit_status = execute_or(ctx, ast->left,
				ast->right, is_child);
	else if (node->type == NODE_PIPE)
		ctx->exit_status = execute_pipe(ctx, ast->left,
				ast->right, is_child);
	return (ctx->exit_status);
}

int	execute(t_shell *ctx, t_ast *ast, int is_child)
{
	t_exec_node	*node;

	if (!ast)
		return (EXIT_SUCCESS);
	node = (t_exec_node *) ast->value;
	if (node->type == NODE_CMD)
		return (execute_command(ctx, node, is_child));
	return (execute_operator(ctx, ast, node, is_child));
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
