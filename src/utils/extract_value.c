/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_extract_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:02:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 20:03:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_value(char *var_content)
{
	char	*equal;

	equal = ft_strchr(var_content, '=');
	if (equal)
		return (ft_strdup(equal + 1));
	return (NULL);
}
