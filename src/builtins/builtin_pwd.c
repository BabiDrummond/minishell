/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:44:24 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/19 17:20:28 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_pwd(t_list *vars)
{
	char	buffer[1024];
	char	*pwd;

	pwd = var_get_value(vars, "PWD");
	if (pwd)
		printf("%s\n", pwd);
	else
	{
		if (getcwd(buffer, sizeof(buffer)) == NULL)
		{
			printf("pwd: error retrieving current directory: \
				getcwd: cannot access parent directories: \
				No such file or directory\n");
			return (EXIT_FAILURE);
		}
		printf("%s\n", buffer);
	}
	return (EXIT_SUCCESS);
}
