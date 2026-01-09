/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:01:46 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/08/21 01:01:17 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"
#include "memft.h"

t_string	*str_new(size_t len)
{
	char	*value;

	value = ft_calloc(len + 1, sizeof(char));
	if (!value)
		return (NULL);
	return (str_new_values(value, len));
}
