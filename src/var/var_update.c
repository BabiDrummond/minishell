/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:40:59 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 02:04:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_update(t_list **vars, t_var *var)
{
	t_var	*curr_var;
	t_list	*current;

	current = *vars;
	while (current)
	{
		curr_var = (t_var *)current->content;
		if (curr_var && curr_var->key && !ft_strcmp(curr_var->key, var->key))
		{
			var_clear(curr_var);
			current->content = var;
			return ;
		}
		current = current->next;
	}
}
