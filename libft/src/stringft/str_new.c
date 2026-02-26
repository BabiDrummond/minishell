/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:01:46 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:31:26 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"
#include "gcft.h"

char	*str_new(size_t len)
{
	char	*value;

	value = ft_calloc(len + 1, sizeof(char));
	return (str_new_values(value, len));
}
