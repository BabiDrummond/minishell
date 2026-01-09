/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:49:24 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:57:35 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stringft.h"

size_t	ft_putstr(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	return (write(1, str, len));
}
