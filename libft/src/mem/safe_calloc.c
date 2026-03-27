/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 02:06:47 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:40:13 by bmoreira         ###   ########.fr       */
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
		printf("Error allocating memory. Terminating now...\n");
		gc_free_all();
		exit(EXIT_FAILURE);
	}
	gc_add(ptr, free);
	return (ptr);
}
