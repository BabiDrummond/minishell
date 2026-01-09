/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:13:14 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/14 21:45:38 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"
#include "memft.h"

t_string	*str_new_values(char *value, size_t len)
{
	t_string	*str;

	str = ft_calloc(1, sizeof(t_string));
	if (!str)
		return (NULL);
	str->value = value;
	str->length = len;
	return (str);
}
