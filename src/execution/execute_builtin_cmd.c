/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:57:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/10 22:32:34 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_builtin_cmd(t_shell *shell, char **argv)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		return (builtin_cd(&shell->vars, argv));
	else if (ft_strcmp(argv[0], "echo") == 0)
		return (builtin_echo(argv));
	else if (ft_strcmp(argv[0], "env") == 0)
		return (builtin_env(shell->vars, argv));
	else if (ft_strcmp(argv[0], "exit") == 0)
		return (builtin_exit(shell, argv));
	else if (ft_strcmp(argv[0], "export") == 0)
		return (builtin_export(&shell->vars, argv));
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (builtin_pwd(shell->vars));
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (builtin_unset(&shell->vars, argv));
	return (EXIT_FAILURE);
}
