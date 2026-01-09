/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:01:46 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:39:11 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

t_string	*str_new(size_t len)
{
	char	*value;

	value = ft_calloc(len + 1, sizeof(char));
	if (!value)
		return (NULL);
	return (str_new_values(value, len));
}
