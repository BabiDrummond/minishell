/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:34:49 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:32:05 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"
#include "gcft.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	gc_add_or_exit(ptr, free);
	return (ptr);
}
