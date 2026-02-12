/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 04:48:09 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 02:03:38 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

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

/*
#include <stdio.h>
int	main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	char * empty = (char*)"";
	printf("%s\n", ft_strnstr(haystack, needle, 0));
	printf("%s\n", ft_strnstr(haystack, needle, -1));
	printf("%s\n", ft_strnstr(haystack, "a", -1));
	printf("%s\n", ft_strnstr(haystack, "c", -1));
	printf("%s\n", ft_strnstr(empty, "", -1));
	printf("%s\n", ft_strnstr(empty, "", 0));
	printf("%s\n", ft_strnstr(empty, "coucou", -1));
	printf("%s\n", ft_strnstr(haystack, "aaabc", 5));
	printf("%s\n", ft_strnstr(empty, "12345", 5));
	printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	printf("%s\n", ft_strnstr(haystack, "cd", 8));
	printf("%s\n", ft_strnstr(haystack, "a", 1));
	printf("%s\n", ft_strnstr("1", "a", 1));
	printf("%s\n", ft_strnstr("22", "b", 2));
}
*/