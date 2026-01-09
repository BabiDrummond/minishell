/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:39:24 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:35:54 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_ptr;

	s_ptr = s;
	while (n--)
		*s_ptr++ = c;
	return (s);
}
