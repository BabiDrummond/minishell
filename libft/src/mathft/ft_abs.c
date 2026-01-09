/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:43:05 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/21 01:36:36 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_abs(long long number)
{
	if (number > 0)
		return (number);
	return (0ULL - (unsigned long long) number);
}
