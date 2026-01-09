/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:42:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:42:53 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

void	lst_dup(t_list *src, t_list *dest, void *(*dup)(void *))
{
	t_node	*node;

	node = src->first;
	while (node)
	{
		lst_add_last(dest, lst_new_node(dup(node->content)));
		node = node->next;
	}
}
