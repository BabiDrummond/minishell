/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:31:35 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:23:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	negative;

	num = 0;
	negative = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			negative *= -1;
	while (ft_isdigit(*nptr))
		num = (num * 10) + *nptr++ - 48;
	return (num * negative);
}
