/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 06:46:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 01:52:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	while (s[++i])
		new[i] = s[i];
	return (new);
}
