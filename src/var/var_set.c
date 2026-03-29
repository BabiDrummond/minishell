/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:39:38 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 23:30:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

int	var_set(t_list **vars, char *key, char *value, int exported)
{
	t_var	*var;

	var = var_create(key, value, exported);
	if (var)
	{
		if (var_get(*vars, var->key))
			var_update(vars, var);
		else
			lst_add_back(vars, lst_new(var));
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
