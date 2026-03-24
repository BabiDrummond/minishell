/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:56:26 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/24 00:56:37 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*append_char(char *str, char c)
{
	char	*new;

	new = ft_calloc(1 + 1, sizeof(char));
	new[0] = c;
	str = ft_strjoin_free(str, new, TRUE, TRUE);
	return (str);
}
