/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:41:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 22:58:36 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int is_valid_key(char *var_content)
// {
// 	int	i;

// 	i = 1;
// 	if (!ft_isalpha(var_content[0]) || !(var_content[0] == '_'))
// 		return (FALSE);
// 	while (var_content[i] &&
// 		(ft_isalnum(var_content[i]) || var_content[i] == '_'))
// 		i++;
// 	if (var_content[i] == '\0' || var_content[i] == '=')
// 		return (TRUE);
// 	return (FALSE);
// }

t_var	*var_create(char *var_content, int exported)
{
	char	*value;
	t_var	*var;

	// if (!is_valid_key(var_content))
	// 	return (NULL);
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
