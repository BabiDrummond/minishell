/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:38:49 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 02:33:49 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*new_str;

	len = 0;
	while (s[len] && len < n)
		len++;
	new_str = (char *)safe_calloc(1, len + 1);
	ft_memcpy(new_str, s, len);
	new_str[len] = '\0';
	return (new_str);
}
