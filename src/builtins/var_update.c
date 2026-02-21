/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:40:59 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 00:41:10 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_update(t_list **vars, t_var *var)
{
	t_var	*var_cmp;
	t_list	*current;

	current = *vars;
	while(current)
	{
		var_cmp = (t_var *)current->content;
		if (var_cmp && var_cmp->key && !ft_strcmp(var_cmp->key, var->key))
		{
			free(var_cmp->value);
			var_cmp->value = var->value;
		}
		current = current->next;
	}
}
