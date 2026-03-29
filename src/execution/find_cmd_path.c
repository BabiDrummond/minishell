/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:22:15 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 22:14:05 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*find_cmd_path(t_list *vars, char *cmd)
{
	char	**env_path;
	char	*cmd_path;
	int		i;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	env_path = ft_split(var_get_value(vars, "PATH"), ':');
	while (env_path[i])
	{
		if (ft_strncmp(env_path[i] + ft_strlen(env_path[i]) - 1, "/", 1) != 0)
			cmd_path = ft_triple_join(env_path[i], "/", cmd);
		else
			cmd_path = ft_strjoin(env_path[i], cmd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		cmd_path = NULL;
		i++;
	}
	return (NULL);
}
