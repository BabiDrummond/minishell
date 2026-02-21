/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:31:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 00:53:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_get(t_list *vars, char *var_key)
{
	t_var	*var;

	if (!vars || !var_key)
		return (NULL);
	while (vars)
	{
		var = (t_var *) vars->content;
		if (var && var->key && !ft_strcmp(var->key, var_key))
			return (var->value);
		vars = vars->next;
	}
	return (NULL);
}
