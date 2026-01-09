/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:18:32 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/08 13:55:23 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsft.h"
#include "memft.h"
#include "memft.h"

void	hs_add(t_hashset *hs, void *key)
{
	size_t		hash;
	t_hsnode	*node;

	hash = hs->hash_func(key, hs->size);
	if (!hs->buckets[hash])
	{
		hs->buckets[hash] = hsnode_new(key);
		hs->count++;
	}
	else
	{
		node = hs->buckets[hash];
		while (node)
		{
			if (hs->compare_func(node->key, key) == 0)
				return ;
			node = node->next;
		}
		node = hsnode_new(key);
		node->next = hs->buckets[hash];
		hs->buckets[hash] = node;
		hs->count++;
	}
	if ((double)hs->count / (double)hs->size > 0.7)
		hs_resize(hs);
}
