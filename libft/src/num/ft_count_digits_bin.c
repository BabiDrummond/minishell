/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_bin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:09:49 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/20 23:12:40 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

int	ft_count_digits_bin(unsigned int num)
{
	unsigned int	mask;
	int				bits;

	mask = 1 << 31;
	bits = sizeof(unsigned int) * BYTE_SIZE;
	while (!(mask & num) && bits--)
		mask = mask >> 1;
	return (bits);
}
