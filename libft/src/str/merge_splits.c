/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_splits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:54:17 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:46:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	**merge_splits(char **first, char **second)
{
	char	**result;
	int		size;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	size = ft_split_size(first) + ft_split_size(second);
	result = safe_calloc(size + 1, sizeof(char *));
	while (first && first[i])
		result[k++] = ft_strdup(first[i++]);
	while (second && second[j])
		result[k++] = ft_strdup(second[j++]);
	return (result);
}
