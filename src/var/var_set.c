/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:39:38 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 00:39:55 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_set(t_list **vars, char *var_content)
{
	t_var	*var;

	var = var_create(var_content, FALSE);
	if (var_get(*vars, var->key))
		var_update(vars, var);
	else
		lst_add_back(vars, lst_new(var));
}
