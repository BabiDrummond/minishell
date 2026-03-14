/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:31:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 01:59:36 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_var	*var_get(t_list *vars, char *key)
{
	t_var	*curr_var;

	if (!vars || !key)
		return (NULL);
	while (vars)
	{
		curr_var = (t_var *) vars->content;
		if (curr_var && curr_var->key && !ft_strcmp(curr_var->key, key))
			return (curr_var);
		vars = vars->next;
	}
	return (NULL);
}

char	*var_get_value(t_list *vars, char *key)
{
	t_var	*var;

	var = var_get(vars, key);
	if (var)
		return (var->value);
	return (NULL);
}
