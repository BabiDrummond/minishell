/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:02:42 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 23:50:50 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_export(t_list **vars, char **args)
{
	char	*key;
	char	*value;
	int		exit_code;
	int		i;

	i = 1;
	exit_code = EXIT_SUCCESS;
	if (!args[i])
		builtin_env(*vars, args);
	else
	{
		while (args[i])
		{
			key = extract_key(args[i]);
			value = extract_value(args[i]);
			if (var_set(vars, key, value, TRUE) == EXIT_FAILURE)
				exit_code = EXIT_FAILURE;
			i++;
		}
	}
	return (exit_code);
}
