/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:30:22 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/14 19:34:43 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t type_size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			size;

	size = nmemb * type_size;
	if (size != 0 && nmemb > (size_t) -1 / type_size)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	p = ptr;
	while (size--)
		*p++ = 0;
	return (ptr);
}
