/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:27:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/21 23:27:12 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "expansion.h"

static int	is_builtin(char *cmd)
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

int	execute_cmd(t_shell *ctx, t_exec_node *node, int is_child)
{
	char	**old_argv;
	char	*join_argv;
	char	**argv;

	node->argv = expand(ctx, node->argv);
	//node->argv = mark_protected_spaces(node->argv);
	old_argv = build_argv(node->argv);
	join_argv = ft_join_split(old_argv, " ");
	argv = split_unquoted(join_argv);
	if (process_redirects(ctx, node->redirs, is_child) == EXIT_FAILURE)
	{
		restore_fds(ctx, is_child);
		ft_split_free(argv);
		return (exit_status(ctx, EXIT_FAILURE, FALSE));
	}
	else
		ctx->exit_status = EXIT_SUCCESS;
	if (argv && argv[0])
	{
		if (is_builtin(argv[0]))
			ctx->exit_status = execute_builtin_cmd(ctx, argv);
		else
			ctx->exit_status = execute_external_cmd(ctx, argv, is_child);
	}
	restore_fds(ctx, is_child);
	ft_split_free(argv);
	return (ctx->exit_status);
}
