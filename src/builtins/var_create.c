/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:41:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 00:41:45 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_var	*var_create(char *var_content, int exported)
{
	char	*value;
	t_var	*var;

	var = ft_calloc(1, sizeof(t_var));
	value = ft_strchr(var_content, '=');
	if (value)
	{
		var->key = ft_substr(var_content, 0, value - var_content);
		var->value = ft_strdup(value + 1);
	}
	else
	{
		var->key = ft_strdup(var_content);
		var->value = ft_strdup("");
	}
	var->exported = exported;
	return (var);
}
