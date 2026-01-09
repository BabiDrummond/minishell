/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:36:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:02:03 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include <stdlib.h>

void	lst_delete_node(t_node *node, void (*free_content)(void*))
{
	if (node->prev)
		node->prev->next = node->next;
	else
		node->list->first = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		node->list->last = node->prev;
	if (node->list->count > 0)
		node->list->count--;
	if (free_content)
		free_content(node->content);
	free(node);
}
