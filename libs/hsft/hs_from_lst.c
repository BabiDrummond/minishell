/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_from_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:02:01 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/08 13:53:54 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include "hsft.h"
#include "mathft.h"
#include "memft.h"

t_hashset	*hs_from_lst( t_list *lst,
	size_t (*hash_func)(void*, size_t),
	int (*compare_func)(void*, void*),
	void (*free_key)(void*)
)
{
	t_node		*node;
	t_hashset	*hs;

	hs = hs_new(next_prime(lst->count * 2), hash_func, compare_func, free_key);
	if (!hs)
		return (NULL);
	node = lst->first;
	while (node)
	{
		hs_add(hs, node->content);
		node = node->next;
	}
	return (hs);
}
