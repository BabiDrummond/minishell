/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:49:12 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/08 13:50:38 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsft.h"
#include "memft.h"

t_hashset	*hs_new( size_t size,
	size_t (*hash_func)(void*, size_t),
	int (*compare_func)(void*, void*),
	void (*free_key)(void*)
)
{
	t_hashset	*hs;

	hs = ft_calloc(1, sizeof(t_hashset));
	if (!hs)
		return (NULL);
	hs->compare_func = compare_func;
	hs->hash_func = hash_func;
	hs->free_func = hs_free;
	hs->size = size;
	hs->buckets = ft_calloc(size, sizeof(t_hsnode *));
	if (!hs->buckets)
	{
		hs_free(hs, free_key);
		return (NULL);
	}
	return (hs);
}
