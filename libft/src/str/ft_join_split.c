/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:58:49 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 02:04:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_join_split(char **split, char *separator)
{
	char	*tmp;
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
		tmp = str;
		str = ft_strjoin(str, split[i]);
		ft_free(&tmp);
		if (i < size - 1)
		{
			tmp = str;
			str = ft_strjoin(str, separator);
			ft_free(&tmp);
		}
		i++;
	}
	return (str);
}
