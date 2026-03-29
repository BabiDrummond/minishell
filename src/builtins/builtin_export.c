/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:02:42 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 17:50:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_export(t_list **vars, char **argv)
{
	char	*key;
	char	*value;
	int		exit_code;
	int		i;

	i = 1;
	exit_code = EXIT_SUCCESS;
	if (!argv[i])
		builtin_env(*vars, argv);
	else
	{
		while (argv[i])
		{
			gc_set_current_scope(GC_SCOPE_GLOBAL);
			key = extract_key(argv[i]);
			value = extract_value(argv[i]);
			gc_set_current_scope(GC_SCOPE_FUNCTION);
			if (var_set(vars, key, value, TRUE) == EXIT_FAILURE)
				exit_code = EXIT_FAILURE;
			i++;
		}
	}
	return (exit_code);
}
