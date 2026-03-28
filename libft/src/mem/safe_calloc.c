/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 02:06:47 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 01:32:28 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "list.h"
#include "gc.h"

void	*safe_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
	{
		perror("Error allocating memory. Terminating now...\n");
		gc_exit(EXIT_FAILURE);
	}
	gc_add(ptr, free);
	return (ptr);
}
