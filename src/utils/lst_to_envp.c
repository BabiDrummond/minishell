/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:50:27 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 23:40:36 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**lst_to_envp(t_list *vars)
{
	t_var	*var;
	char	**envp;
	int		size;
	int		i;

	i = 0;
	size = lst_size(vars);
	envp = safe_calloc(size + 1, sizeof(char *));
	while (vars && i < size)
	{
		var = (t_var *) vars->content;
		if (var && var->exported)
			envp[i++] = ft_triple_join(var->key, "=", var->value);
		vars = vars->next;
	}
	return (envp);
}
