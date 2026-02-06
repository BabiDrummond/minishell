/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:27:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/06 20:49:28 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_echo(t_shell *info, char *string);
void	execute_cd(t_shell *info, char *dir);
void	execute_pwd(t_shell *info);
void	execute_export(t_shell *info, char *string);
void	execute_unset(t_shell *info, char *string);
void	execute_env(t_shell *info, char *string);
void	execute_exit(t_shell *info, char *string);

void	execute_echo(char *string)
{	
	if (string == NULL)
		return ;
	printf("%s", string);
	if (n_option != NULL)
		printf("\n");
}
