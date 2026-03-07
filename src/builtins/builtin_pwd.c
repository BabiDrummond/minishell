/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:44:24 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 19:57:04 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_list *vars)
{
	char	buffer[1024];
	char	*pwd;

	pwd = var_get_value(vars, "PWD");
	if (pwd)
		printf("%s\n", pwd);
	else
	{
		getcwd(buffer, sizeof(buffer));
		printf("%s\n", buffer);
	}
	return (EXIT_SUCCESS);
}
