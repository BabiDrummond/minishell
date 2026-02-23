/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:02:42 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 00:05:33 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_export(t_list **vars, char *var_content)
{
	char	**split;
	int		i;

	i = 0;
	if (!var_content)
		builtin_env(*vars);
	else
	{
		split = ft_split(var_content, ' ');
		while (split[i])
			var_set(vars, split[i++], TRUE);
		ft_split_free(split);
	}
}
