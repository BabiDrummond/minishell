/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:54:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 01:54:50 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

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
