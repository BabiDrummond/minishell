/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trimmed_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:58:54 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 01:59:06 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_trimmed_length(char *str)
{
	int	i;
	int	len;
	int	in_space;

	i = 0;
	len = 0;
	in_space = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			in_space = 1;
		else
		{
			if (in_space && len > 0)
				len++;
			in_space = 0;
			len++;
		}
		i++;
	}
	return (len);
}
