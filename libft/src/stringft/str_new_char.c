/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:18:47 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:39:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

t_string	*str_new_char(char c)
{
	t_string	*str;

	str = str_new(1);
	if (!str)
		return (NULL);
	str->value[0] = c;
	return (str);
}
