/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:01:38 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:30:49 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

t_node	*lst_add_before(t_node *target, t_node *node)
{
	if (lst_is_invalid(target))
		return (NULL);
	if (!lst_is_detached(node))
		return (NULL);
	if (lst_is_equal(target, node))
		return (NULL);
	if (lst_is_first(target))
		return (lst_add_first(target->list, node));
	node->list = target->list;
	node->prev = target->prev;
	node->next = target;
	node->prev->next = node;
	target->prev = node;
	node->list->count++;
	return (node);
}
