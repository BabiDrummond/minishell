/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:44:45 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 00:01:43 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_env(t_list *vars, char **argv)
{
	t_var	*var;

	if (argv[1])
		return (print_error(ft_replace("env: '%s': No such file or directory"
					"\n", "%s", argv[1]), CMD_NOT_FOUND));
	while (vars)
	{
		var = (t_var *) vars->content;
		if (var && var->value && var->exported)
			printf("%s=%s\n", var->key, var->value);
		vars = vars->next;
	}
	return (EXIT_SUCCESS);
}
