/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:54:01 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:25:04 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	start = 0;
	if (!s1 || !set)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (len > start && ft_strchr(set, s1[len - 1]))
		len--;
	return (ft_substr(s1, start, len - start));
}

// int main(void)
// {
// 	#include <stdio.h>
// 	printf("%s\n", ft_strtrim("anana", "a"));
// }
