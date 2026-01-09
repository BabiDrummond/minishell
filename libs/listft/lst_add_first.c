/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:14:11 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/13 22:53:27 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include <stddef.h>

t_node	*lst_add_first(t_list *lst, t_node *node)
{
	if (!lst || !node)
		return (NULL);
	node->list = lst;
	node->prev = NULL;
	if (lst->count)
	{
		lst->first->prev = node;
		node->next = lst->first;
	}
	else
	{
		node->next = NULL;
		lst->last = node;
	}
	lst->first = node;
	lst->count++;
	return (node);
}
