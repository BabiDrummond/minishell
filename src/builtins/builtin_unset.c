/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:46:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/19 17:20:35 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_unset(t_list **vars, char **argv)
{
	int		exit_code;
	int		i;

	i = 1;
	exit_code = EXIT_SUCCESS;
	if (!argv[i])
		return (exit_code);
	while (argv[i])
	{
		if (!is_valid_key(argv[i])
			&& printf("unset: `%s': invalid parameter name\n", argv[i]))
			exit_code = EXIT_FAILURE;
		else
			var_unset(vars, argv[i]);
		i++;
	}
	return (exit_code);
}
