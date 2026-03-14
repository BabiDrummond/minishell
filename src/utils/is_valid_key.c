/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 03:05:57 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 01:59:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_valid_key(char *var_content)
{
	int	i;

	i = 1;
	if (!var_content || !var_content[0])
		return (FALSE);
	if (!ft_isalpha(var_content[0]) && !(var_content[0] == '_'))
		return (FALSE);
	while (ft_isalnum(var_content[i]) || var_content[i] == '_')
		i++;
	return (var_content[i] == '\0');
}
