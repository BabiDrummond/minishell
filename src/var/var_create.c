/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:41:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 00:01:55 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

t_var	*var_create(char *key, char *value, int exported)
{
	t_var	*var;

	if (!is_valid_key(key))
	{
		ft_putstr_fd(ft_replace("export: `%s': not a valid identifier\n",
				"%s", key), 2);
		return (NULL);
	}
	var = safe_calloc(1, sizeof(t_var));
	var->key = key;
	var->value = value;
	var->exported = exported;
	return (var);
}
