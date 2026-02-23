/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:34:24 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/22 23:17:59 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*build_cmd_path(t_list *vars, char *cmd)
{
	char	**path;
	char	*cmd_path;
	int		i;

	i = 0;
	path = ft_split(var_get_value(vars, "PATH"), ':');
	while (path[i])
	{
		if (ft_strncmp(path[i] + ft_strlen(path[i]) - 1, "/", 1) != 0)
		{
			cmd_path = ft_triple_join(path[i], "/", cmd);
			if (!access(cmd_path, F_OK))
				return (cmd_path);
		}
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	return (NULL);
}
