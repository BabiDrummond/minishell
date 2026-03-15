/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:27:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/14 21:47:48 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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
	char	**argv;
	int		exit_status;

	argv = build_argv(node->argv);
	if (is_builtin(argv[0]))
		exit_status = execute_builtin_cmd(ctx, argv);
	else
		exit_status = execute_external_cmd(ctx, argv, is_child);
	ft_split_free(argv);
	return (exit_status);
}
