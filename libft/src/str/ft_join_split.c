/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:58:49 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:24:40 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_join_split(char **split, char *separator)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	str = ft_strdup("");
	if (!split || !*split)
		return (str);
	size = ft_split_size(split);
	while (i < size)
	{
		str = ft_strjoin(str, split[i]);
		if (i < size - 1)
			str = ft_strjoin(str, separator);
		i++;
	}
	return (str);
}
