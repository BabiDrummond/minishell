/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_extract_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:02:11 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 20:03:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_key(char *var_content)
{
	char	*equal;

	equal = ft_strchr(var_content, '=');
	if (equal)
		return (ft_substr(var_content, 0, equal - var_content));
	return (ft_strdup(var_content));
}
