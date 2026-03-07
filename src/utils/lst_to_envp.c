/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:50:27 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 01:50:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_envp(t_list *vars)
{
	t_var	*var;
	char	**envp;
	char	**start;

	envp = ft_calloc(lst_size(vars) + 1, sizeof(char *));
	start = envp;
	while (vars)
	{
		var = (t_var *) vars->content;
		if (var && var->exported)
			*envp++ = ft_triple_join(var->key, "=", var->value);
		vars = vars->next;
	}
	return (start);
}
