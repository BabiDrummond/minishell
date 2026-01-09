/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:55:10 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:07:14 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsft.h"
#include <stdlib.h>

void	hs_free(t_hashset *hs, void (*free_key)(void*))
{
	size_t		i;
	t_hsnode	*node;
	t_hsnode	*next;

	i = 0;
	while (i < hs->size)
	{
		node = hs->buckets[i];
		while (node)
		{
			next = node->next;
			if (free_key)
				free_key(node->key);
			free(node);
			node = next;
		}
		i++;
	}
	free(hs->buckets);
	free(hs);
}
