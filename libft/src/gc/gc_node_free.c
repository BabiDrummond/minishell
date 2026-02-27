/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_node_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:24:35 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:28:25 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_node_free(t_gc_node *gc_node)
{
	if (gc_node->destructor)
		gc_node->destructor(gc_node->link.content);
	free(gc_node);
}
