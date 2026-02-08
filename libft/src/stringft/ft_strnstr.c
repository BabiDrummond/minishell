/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 04:48:09 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 02:01:25 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !len)
		return (NULL);
	if (!little)
		return ((char *)(big));
	while (len-- && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && j <= len)
		{
			if (!little[j + 1])
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
