/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:40:57 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:38:37 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

size_t	ft_strlen(const char *s)
{
	const char	*s_start;

	s_start = s;
	while (*s)
		s++;
	return (s - s_start);
}
