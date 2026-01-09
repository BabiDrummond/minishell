/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:39:25 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:30:59 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

t_node	*lst_add_last(t_list *lst, t_node *node)
{
	if (!lst || !node)
		return (NULL);
	node->list = lst;
	node->next = NULL;
	if (lst->count)
	{
		node->prev = lst->last;
		lst->last->next = node;
	}
	else
	{
		node->prev = NULL;
		lst->first = node;
	}
	lst->last = node;
	lst->count++;
	return (node);
}
