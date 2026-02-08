/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:53:48 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/07 21:02:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || (!*s1 && !*s2))
		return (0);
	while (n-- && (*s1 || *s2) && (*s1++ == *s2++))
		;
	return ((unsigned char)*--s1 - (unsigned char)*--s2);
}
