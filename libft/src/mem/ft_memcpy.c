/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:36:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:22:37 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	if (!dest && !src)
		return (NULL);
	temp = (unsigned char *)dest;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (temp);
}
