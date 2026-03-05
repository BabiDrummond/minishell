/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:39:38 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 00:05:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_set(t_list **vars, char *key, char *value, int exported)
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
}
