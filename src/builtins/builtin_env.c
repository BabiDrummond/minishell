/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:44:45 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/09 16:45:09 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_list *vars, char **argv)
{
	t_var	*var;

	if (argv[1])
	{
		printf("env: '%s': No such file or directory\n", argv[1]);
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
