/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:15:12 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/08 12:26:44 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsft.h"
#include "mathft.h"
#include "memft.h"
#include <stdlib.h>

static void	rehash_bucket(t_hashset *temp, t_hsnode *node)
{
	t_hsnode	*next;

	while (node)
	{
		next = node->next;
		node->next = NULL;
		hs_add(temp, node->key);
		node = next;
	}
}

void	hs_resize(t_hashset *hs)
{
	t_hashset	temp;
	size_t		i;

	temp.count = 0;
	temp.size = next_prime(hs->count * 2);
	temp.buckets = ft_calloc(temp.size, sizeof(t_hsnode *));
	temp.hash_func = hs->hash_func;
	if (!temp.buckets)
		return ;
	i = 0;
	while (i < hs->size)
	{
		rehash_bucket(&temp, hs->buckets[i]);
		i++;
	}
	free(hs->buckets);
	hs->buckets = temp.buckets;
	hs->size = temp.size;
	hs->count = temp.count;
}
