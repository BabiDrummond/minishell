/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:25:33 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 19:16:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_triple_join(char *s1, char *s2, char *s3)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1,
			sizeof(char));
	if (!new)
		return (NULL);
	while (s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	j = 0;
	while (s3[j])
		new[i++] = s3[j++];
	return (new);
}
