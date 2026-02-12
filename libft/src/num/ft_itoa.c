/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:17:32 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:23:38 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		negative;

	negative = 0;
	len = ft_count_digits(n, 10);
	str = ft_calloc(len + 1, sizeof(char));
	if (n == INT_MIN)
		return ((char *) ft_memcpy(str, "-2147483648", len));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[negative] = '-';
		negative++;
	}
	while (--len >= negative)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

/*
int main(void)
{	
	#include <stdio.h>
	printf("%s\n", ft_itoa(2147483647));
}
*/