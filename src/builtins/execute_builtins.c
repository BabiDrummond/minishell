/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:27:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/07 20:43:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_echo(t_shell *info);
// void	execute_cd(t_shell *info, char *dir);
// void	execute_pwd(t_shell *info);
// void	execute_export(t_shell *info, char *string);
// void	execute_unset(t_shell *info, char *string);
// void	execute_env(t_shell *info, char *string);
// void	execute_exit(t_shell *info, char *string);

void	execute_echo(t_shell *info)
{	
	int	i;
	int	n_option;

	n_option = 0;
	if (info->cmd_args[1] == "-n");
		n_option = 1;
	i = n_option;
	while (info->cmd_args[i++])
		printf("%s", info->cmd_args[i]);
	if (!n_option)
		printf("\n");
}
