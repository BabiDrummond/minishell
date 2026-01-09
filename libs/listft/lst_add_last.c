/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:39:25 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/13 22:53:14 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include "stddef.h"

t_node	*lst_add_last(t_list *lst, t_node *node)
{
	if (!lst || !node)
		return (NULL);
	node->list = lst;
	node->next = NULL;
	if (lst->count)
	{
		node->prev = lst->last;
		lst->last->next = node;
	}
	else
	{
		node->prev = NULL;
		lst->first = node;
	}
	lst->last = node;
	lst->count++;
	return (node);
}
