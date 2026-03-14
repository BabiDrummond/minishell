/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:41:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 01:59:32 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_var	*var_create(char *key, char *value, int exported)
{
	t_var	*var;

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
