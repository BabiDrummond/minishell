/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:31:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 19:20:03 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_get(t_list *vars, char *var_name)
{
	t_var	*var;

	if (!vars || !var_name)
		return (NULL);
	while (vars)
	{
		var = (t_var *) vars->content;
		if (var && var->key && !ft_strcmp(var->key, var_name))
			return (var->value);
		vars = vars->next;
	}
	return (NULL);
}
