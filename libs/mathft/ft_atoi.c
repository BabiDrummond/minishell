/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:21:07 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/21 01:05:39 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"
#include "charft.h"

int	ft_atoi(const char *nptr)
{
	int	acumulator;
	int	is_negative;

	is_negative = 1;
	acumulator = 0;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_negative = -1;
	while (ft_isdigit(*nptr))
	{
		acumulator = acumulator * 10 + (*nptr - '0');
		nptr++;
	}
	return (acumulator * is_negative);
}
