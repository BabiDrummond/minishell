/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:46:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 19:58:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_list **vars, char **args)
{
	int		exit_code;
	int		i;

	i = 1;
	exit_code = EXIT_SUCCESS;
	if (!args[i])
		return (exit_code);
	while (args[i])
	{
		if (!is_valid_key(args[i])
			&& printf("unset: `%s': invalid parameter name\n", args[i]))
			exit_code = EXIT_FAILURE;
		else
			var_unset(vars, args[i]);
		i++;
	}
	return (exit_code);
}
