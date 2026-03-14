/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/13 23:18:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_and(t_shell *shell, t_ast *left, t_ast *right, int is_child)
{
	shell->exit_status = execute(shell, left, is_child);
	if (shell->exit_status == EXIT_SUCCESS)
		shell->exit_status = execute(shell, right, is_child);
	return (shell->exit_status);
}

int	execute_or(t_shell *shell, t_ast *left, t_ast *right, int is_child)
{
	shell->exit_status = execute(shell, left, is_child);
	if (shell->exit_status != EXIT_SUCCESS)
		shell->exit_status = execute(shell, right, is_child);
	return (shell->exit_status);
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

int	print_error_and_return(t_shell *shell, char *error_msg, int exit_status)
{
	perror(error_msg);
	shell->exit_status = exit_status;
	return (shell->exit_status);
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

int	execute_operator(t_shell *shell, t_ast *node, t_token *token, int is_child)
{
	char	*operator;

	operator = (char *)token->link.content;
	// if (ft_strcmp(operator, "|") == 0)
	// 	return (execute_pipe(shell, node->left, node->right, is_child));
	if (ft_strcmp(operator, "&&") == 0)
		shell->exit_status = execute_and(shell, node->left,
				node->right, is_child);
	else if (ft_strcmp(operator, "||") == 0)
		shell->exit_status = execute_or(shell, node->left,
				node->right, is_child);
	// else if (ft_strcmp(operator, "<") == 0)
	// 	return (execute_redir_in(shell, node->left, node->right, is_child));
	// else if (ft_strcmp(operator, ">") == 0)
	// 	return (execute_redir_out(shell, node->left, node->right, is_child));
	// else if (ft_strcmp(operator, ">>") == 0)
	// 	return (execute_redir_append(shell, node->left, node->right, is_child));
	return (shell->exit_status);
}

int	execute(t_shell *shell, t_ast *node, int is_child)
{
	t_token	*token;

	if (!node)
		return (0);
	token = (t_token *)node->value;
	if (token && token->is_operator)
		return (execute_operator(shell, node, token, is_child));
	return (execute_command(shell, token, is_child));
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
