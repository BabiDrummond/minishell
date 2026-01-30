/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:30:22 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 12:44:35 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"

void	*ft_calloc(size_t nmemb, size_t type_size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			size;

	size = nmemb * type_size;
	if (size != 0 && nmemb > (size_t) -1 / type_size)
		return (NULL);
	ptr = ft_malloc(size);
	p = ptr;
	while (size--)
		*p++ = 0;
	return (ptr);
}
