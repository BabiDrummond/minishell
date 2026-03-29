/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:55:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 17:49:07 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*envp_to_lst(char **envp)
{
	t_list	*vars;
	t_var	*var;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	vars = NULL;
	gc_set_current_scope(GC_SCOPE_GLOBAL);
	while (envp && envp[i])
	{	
		key = extract_key(envp[i]);
		value = extract_value(envp[i]);
		var = var_create(key, value, TRUE);
		lst_add_back(&vars, lst_new(var));
		i++;
	}
	gc_set_current_scope(GC_SCOPE_FUNCTION);
	return (vars);
}
