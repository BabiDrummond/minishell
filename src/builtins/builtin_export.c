/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:02:42 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 01:59:00 by bmoreira         ###   ########.fr       */
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

void	builtin_export(t_list **vars, char **args)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	if (!args[i])
		builtin_env(*vars);
	else
	{
		while (args[i])
		{
			key = extract_key(args[i]);
			value = extract_value(args[i]);
			var_set(vars, key, value, TRUE);
			i++;
		}
	}
}
