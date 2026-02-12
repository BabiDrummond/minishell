/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:02:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:23:50 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	put_case(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchr(va_arg(args, int)));
	if (c == 's')
		return (ft_put_s(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_put_n(va_arg(args, int), "0123456789", 10));
	if (c == 'u')
		return (ft_putul(va_arg(args, unsigned int), "0123456789", 10));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (c == 'x')
		return (ft_putul(va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (ft_putul(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && ft_strchr("cspdiuxX", *++s))
			count += put_case(*s++, args);
		else
			count += ft_putchr(*s++);
	}
	va_end(args);
	return (count);
}
