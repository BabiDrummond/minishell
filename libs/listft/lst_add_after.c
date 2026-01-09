/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_after.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:01:51 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/13 22:53:46 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include "stddef.h"

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
