/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 06:46:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/07 21:01:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = -1;
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (s[++i])
		new[i] = s[i];
	return (new);
}
