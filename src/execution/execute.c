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

// int	get_stdin_fd(t_token *token)
// {
// 	char	**argv;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = -1;
// 	argv = build_argv(token);
// 	while (argv && argv[i])
// 	{
// 		if (fd != -1)	
// 			close(fd);
// 		fd = open(argv[i], O_RDONLY);
// 		if (fd < 0)
// 		{
// 			perror("fd");
// 			ft_split_free(argv);
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	ft_split_free(argv);
// 	return (fd);
// }

// int	print_error_and_return(t_shell *ctx, char *error_msg, int exit_status)
// {
// 	perror(error_msg);
// 	ctx->exit_status = exit_status;
// 	return (ctx->exit_status);
// }

// int	execute_redir_in(t_shell *ctx, t_ast *left, t_ast *right, int is_child)
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

// int	get_fd(char *redir_target, int redir_type, int *stdin_fd, int *stdout_fd)
// {
// 	if (stdin_fd != -1)
// 		close(stdin_fd);
// 	if (stdout_fd != -1)
// 		close(stdout_fd);
// 	if (redir_type == REDIR_IN)
// 	{
// 		stdin_fd = open(redir_target, O_RDONLY);
// 		if (stdin_fd < 0)
// 		{
// 			perror(errno);
// 			return (EXIT_FAILURE);
// 		}
// 	}
// }

// int	process_redirects(t_list *redirs)
// {
// 	t_list	*node;
// 	t_redir	*redir;
// 	int		stdin_fd;
// 	int		stdout_fd;

// 	stdin_fd = -1;
// 	stdout_fd = -1;
// 	while (node)
// 	{
// 		redir = (t_redir *) node->content;
// 		get_fd(redir->target, redir->type, stdin_fd, stdout_fd);
// 		node->next;
// 	}
// }

int	execute(t_shell *ctx, t_ast *ast, int is_child)
{
	t_exec_node	*node;

	if (!ast)
		return (EXIT_SUCCESS);
	node = (t_exec_node *) ast->value;
	if (node->argv && node->type == NODE_CMD)
		return (execute_cmd(ctx, node, is_child));
	return (execute_operator(ctx, ast, node, is_child));
}
