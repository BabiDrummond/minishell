/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:11:29 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:24:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	char	*temp;

	new_str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	temp = new_str;
	if (!new_str)
		return (NULL);
	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;
	return (temp);
}
/*
int main(void)
{
	char *str1 = "manhê, phineas e pherb ";
	char *str2 = "estão fazendo a abertura da serie";

	printf("%s\n", ft_strjoin(str1, str2));
}
*/