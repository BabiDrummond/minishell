/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:46:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 03:13:03 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unset(t_list **vars, char **args)
{

	int		i;

	i = 1;
	if (!args[i])
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	while (args[i])
	{
		if (!is_valid_key(args[i]))
			printf("unset: `%s': invalid parameter name\n", args[i]);
		else
			var_unset(vars, args[i]);
		i++;
	}
}
