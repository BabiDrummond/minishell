/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:48:38 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:22:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	else if (dest > src)
	{
		src += n - 1;
		dest += n - 1;
		while (n--)
			*(unsigned char *)dest-- = *(unsigned char *)src--;
	}
	return (temp);
}
