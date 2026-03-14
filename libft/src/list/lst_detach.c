/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_detach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:36:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:31:19 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_node	*lst_detach(t_head *list, t_node *node)
{
	if (!list || !node)
		return (NULL);
	if (node->prev)
		node->prev->next = node->next;
	else
		list->first = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		list->last = node->prev;
	list->count--;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
