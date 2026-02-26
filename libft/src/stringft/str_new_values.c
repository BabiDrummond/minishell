/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:13:14 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:39:06 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

char	*str_new_values(char *value, size_t len)
{
	char	*str;

	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	str = value;
	(void) len;
	return (str);
}
