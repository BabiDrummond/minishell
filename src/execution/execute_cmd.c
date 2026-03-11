/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:27:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/10 20:27:55 by bmoreira         ###   ########.fr       */
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
