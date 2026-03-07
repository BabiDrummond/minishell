/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:libft/src/list/lst_add_last.c
/*   Created: 2025/08/13 17:39:25 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 13:02:49 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_node	*lst_add_last(t_head *lst, t_node *node)
========
/*   Created: 2026/02/21 00:39:38 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 19:45:42 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_set(t_list **vars, char *key, char *value, int exported)
>>>>>>>> builtins:src/var/var_set.c
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
