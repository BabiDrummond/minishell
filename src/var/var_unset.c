/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:35:54 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 01:45:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_unset(t_list **vars, char *var_key)
{
	t_list	*current;
	t_var	*curr_var;

	current = *vars;
	while (current)
	{
		curr_var = (t_var *) current->content;
		if (ft_strcmp(curr_var->key, var_key) == 0)
		{
			lst_del_node(vars, current, var_clear);
			return ;
		}
		current = current->next;
	}
}
