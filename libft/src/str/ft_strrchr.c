/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:41:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:24:55 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s) + 1;
	while (len--)
		if (s[len] == (char) c)
			return ((char *) s + len);
	return (0);
}

/*
int main(void)
{
	#include <stdio.h>

	printf("%s\n", ft_strrchr("oie td bem?", 'i'));
}
*/