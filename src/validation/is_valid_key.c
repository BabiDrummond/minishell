/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:24:58 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/22 23:26:01 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_valid_key(char *var_content)
{
	int	i;

	i = 1;
	if (!ft_isalpha(var_content[0]) && !(var_content[0] == '_'))
		return (FALSE);
	while (ft_isalnum(var_content[i]) || var_content[i] == '_')
		i++;
	return (var_content[i] == '\0' || var_content[i] == '=');
}
