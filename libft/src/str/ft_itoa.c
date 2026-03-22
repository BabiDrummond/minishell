/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:17:32 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/21 21:40:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	ft_count_digits(int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0 && ++len)
		n *= -1;
	while (n && ++len)
		n = n / base;
	return (len);
}

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
