/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:44:45 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 00:44:25 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(t_list *vars)
{
	t_var	*var;

	while(vars)
	{
		var = (t_var *) vars->content;
		if (var->exported)
			printf("%s=%s\n", var->key, var->value);
		vars = vars->next;
	}
}
