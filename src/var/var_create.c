/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:41:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 03:06:13 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_key(char *var_content)
{
	char	*equal;

	equal = ft_strchr(var_content, '=');
	if (equal)
		return (ft_substr(var_content, 0, equal - var_content));
	return (ft_strdup(var_content));
}

static char	*extract_value(char *var_content)
{
	char	*equal;

	equal = ft_strchr(var_content, '=');
	if (equal)
		return (ft_strdup(equal + 1));
	return (NULL);
}

t_var	*var_create(char *var_content, int exported)
{
	t_var	*var;
	char	*key;
	char	*value;

	key = extract_key(var_content);
	value = extract_value(var_content);
	if (!is_valid_key(key))
	{
		printf("export: `%s': not a valid identifier\n", key);
		return (free(key), free(value), NULL);
	}
	var = ft_calloc(1, sizeof(t_var));
	if (!var)
		return (free(key), free(value), NULL);
	var->key = key;
	var->value = value;
	var->exported = exported;
	return (var);
}
