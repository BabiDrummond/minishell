/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:31:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/22 23:15:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*var_get(t_list *vars, char *var_key)
{
	t_var	*var;

	if (!vars || !var_key)
		return (NULL);
	while (vars)
	{
		var = (t_var *) vars->content;
		if (var && var->key && !ft_strcmp(var->key, var_key))
			return (var);
		vars = vars->next;
	}
	return (NULL);
}

char	*var_get_value(t_list *vars, char *var_key)
{
	t_var	*var;

	var = var_get(vars, var_key);
	if (var)
		return (var->value);
	return (NULL);
}
