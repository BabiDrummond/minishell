/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:39:38 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 17:53:01 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

int	var_set(t_list **vars, char *key, char *value, int exported)
{
	t_var	*var;

	gc_set_current_scope(GC_SCOPE_GLOBAL);
	var = var_create(key, value, exported);
	gc_set_current_scope(GC_SCOPE_FUNCTION);
	if (var)
	{
		gc_set_current_scope(GC_SCOPE_GLOBAL);
		if (var_get(*vars, var->key))
			var_update(vars, var);
		else
			lst_add_back(vars, lst_new(var));
		gc_set_current_scope(GC_SCOPE_FUNCTION);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
