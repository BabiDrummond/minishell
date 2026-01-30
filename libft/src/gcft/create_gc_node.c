/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_gc_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:24:35 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:27:43 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcft.h"

t_gc_node	*create_gc_node(void *ptr, void (*destructor)(void *))
{
	t_gc_node	*item;

	item = (t_gc_node *) malloc(sizeof(t_gc_node));
	item->link.content = ptr;
	item->link.list = NULL;
	item->link.next = NULL;
	item->link.prev = NULL;
	item->destructor = destructor;
	return (item);
}
