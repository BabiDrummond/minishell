/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:44:45 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 23:31:38 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_list *vars, char **args)
{
	t_var	*var;

	if (args[1])
	{
		printf("env: '%s': No such file or directory\n", args[1]);
		return (CMD_NOT_FOUND);
	}
	while (vars)
	{
		var = (t_var *) vars->content;
		if (var && var->value && var->exported)
			printf("%s=%s\n", var->key, var->value);
		vars = vars->next;
	}
	return (EXIT_SUCCESS);
}
