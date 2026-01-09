/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:22:13 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/08 12:21:16 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsft.h"

void	hs_foreach(t_hashset *hs, void (*callback)(void*))
{
	size_t		i;
	t_hsnode	*node;

	i = 0;
	while (i < hs->size)
	{
		node = hs->buckets[i];
		while (node)
		{
			callback(hs->buckets[i]->key);
			node = node->next;
		}
		i++;
	}
}
