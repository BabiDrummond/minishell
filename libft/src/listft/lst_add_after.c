/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_after.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:01:51 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:30:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

t_node	*lst_add_after(t_node *target, t_node *node)
{
	if (lst_is_invalid(target))
		return (NULL);
	if (!lst_is_detached(node))
		return (NULL);
	if (lst_is_equal(target, node))
		return (NULL);
	if (lst_is_last(target))
		return (lst_add_last(target->list, node));
	node->list = target->list;
	node->prev = target;
	node->next = target->next;
	node->next->prev = node;
	target->next = node;
	node->list->count++;
	return (node);
}
