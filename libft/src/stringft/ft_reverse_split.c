/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:58:49 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/07 23:59:10 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringft.h"

char	*ft_reverse_split(char **split, int size, char c)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("");
	while (i < size)
	{
		tmp = str;
		str = ft_strjoin(str, split[i]);
		ft_free(&tmp);
		if (i < size - 1)
		{
			tmp = str;
			str = ft_strjoin(str, &c);
			ft_free(&tmp);
		}
		i++;
	}
	return (str);
}
