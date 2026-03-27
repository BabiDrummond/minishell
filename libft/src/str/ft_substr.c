/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:13:20 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:33:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = safe_calloc(len + 1, sizeof(char));
	ft_memcpy(substr, (s + start), len);
	return (substr);
}
