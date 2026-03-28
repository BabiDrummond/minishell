/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:46:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 02:35:32 by bcosta-b         ###   ########.fr       */
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
		if (!is_valid_key(argv[i]))
			exit_code = EXIT_FAILURE;
		else
			var_unset(vars, argv[i]);
		i++;
	}
	return (exit_code);
}
