/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:42:57 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/11 23:43:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_shell *info)
{	
	char	*str;
	int		n_option;
	int		i;

	i = 0;
	n_option = 0;
	while (ft_strncmp(info->cmd_args[++i], "-n", 2) == 0)
		n_option++;
	str = ft_join_split(info->cmd_args + i, " ");
	printf("%s", str);
	if (!n_option)
		printf("\n");
}
