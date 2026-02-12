/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:15:31 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:24:31 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen(src);
	if (!dst)
		return (size + src_len);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	while ((dst_len + i < size - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char src[] = "Oi voce esta bem?aaa";
	char dst[] = " BANANA MACACO CACO";
	char src2[] = "Oi voce esta bem?aaa";
	char dst2[] = " BANANA MACACO CACO";

	printf("%s %s %zu\n", src, dst, ft_strlcat(NULL, src, 0));
	printf("%s %s\n", src, dst);
	printf("%s %s %zu\n", src2, dst2, strlcat(NULL, src2, 0));
	printf("%s %s\n", src2, dst2);	
}
*/