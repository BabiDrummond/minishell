/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:29:54 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/03 14:49:06 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_free_all(void)
{
	t_head		*gc;
	t_gc_node	*node;
	t_gc_node	*prev;

	gc = get_collector();
	node = (t_gc_node *)gc->last;
	while (node)
	{
		prev = (t_gc_node *)node->link.prev;
		gc_node_free(node);
		node = prev;
	}
	gc->first = NULL;
	gc->last = NULL;
	gc->count = 0;
	gc_set_current_scope(GC_SCOPE_GLOBAL);
}
