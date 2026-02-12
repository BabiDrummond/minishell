/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:43:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 00:43:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	**ft_split_free(char **split)
{
	int	i;

	i = 0;
	if (!split || !*split)
		return (NULL);
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}
