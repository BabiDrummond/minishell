/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:22:15 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/06 23:36:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*find_cmd_path(t_list *vars, char *cmd)
{
	char	**path_env;
	char	*path_cmd;
	int		i;

	i = 0;
	if (!access(cmd, F_OK))
		return (cmd);
	path_env = ft_split(var_get_value(vars, "PATH"), ':');
	while (path_env[i])
	{
		if (ft_strncmp(path_env[i] + ft_strlen(path_env[i]) - 1, "/", 1) != 0)
			path_cmd = ft_triple_join(path_env[i], "/", cmd);
		else
			path_cmd = ft_strjoin_free(path_env[i], cmd, FALSE, FALSE);
		if (!access(path_cmd, F_OK))
			return (path_cmd);
		free(path_cmd);
		path_cmd = NULL;
		i++;
	}
	return (NULL);
}
