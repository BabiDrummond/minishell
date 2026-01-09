/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:05:53 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/14 21:45:07 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"
#include "memft.h"

t_string	*str_dup(const char *s)
{
	t_string	*str;
	size_t		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = str_new(len);
	if (!str)
		return (NULL);
	ft_memcpy(str->value, s, len);
	return (str);
}
