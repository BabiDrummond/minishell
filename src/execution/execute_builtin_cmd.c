/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:57:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 23:57:38 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_builtin_cmd(t_list *vars, char **argv)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		return (builtin_cd(&vars, argv));
	else if (ft_strcmp(argv[0], "echo") == 0)
		return (builtin_echo(argv));
	else if (ft_strcmp(argv[0], "env") == 0)
		return (builtin_env(vars, argv));
	// else if (ft_strcmp(argv[0], "exit") == 0)
	// 	return (builtin_exit());
	else if (ft_strcmp(argv[0], "export") == 0)
		return (builtin_export(&vars, argv));
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (builtin_pwd(vars));
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (builtin_unset(&vars, argv));
	return (EXIT_FAILURE);
}
