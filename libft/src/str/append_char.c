/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:56:26 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 02:33:42 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*append_char(char *str, char c)
{
	char	*new;

	new = safe_calloc(1 + 1, sizeof(char));
	new[0] = c;
	str = ft_strjoin(str, new);
	return (str);
}
