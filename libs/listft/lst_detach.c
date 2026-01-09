/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_detach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:36:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 11:56:41 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include <stdlib.h>
#include <unistd.h>

t_node	*lst_detach(t_list *list, t_node *node)
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
