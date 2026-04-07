/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:35:54 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 23:30:32 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void	var_unset(t_list **vars, char *key)
{
	t_list	*current;
	t_var	*curr_var;

	current = *vars;
	while (current)
	{
		curr_var = (t_var *) current->content;
		if (ft_strcmp(curr_var->key, key) == 0)
		{
			lst_del_node(vars, current);
			return ;
		}
		current = current->next;
	}
}
