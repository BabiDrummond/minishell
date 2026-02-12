/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:31:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/11 23:32:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(t_list *env, char *var_name)
{
	int	var_len;

	var_len = ft_strlen(var_name);
	while (env)
	{
		if (ft_strncmp(env->content, var_name, var_len) == 0)
			return (ft_split(env->content, '=')[1]);
		env = env->next;
	}
	return (NULL);
}
