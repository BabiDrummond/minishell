/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:34:24 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 19:36:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*build_cmd_path(t_shell *info, char *cmd)
// {
// 	char	**path;
// 	char	*cmd_path;
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	path = ft_split(get_env_var(info->vars, "PATH"), ':');
// 	while (path[i])
// 	{
// 		if (ft_strncmp(path[i] + ft_strlen(path[i]) - 1, "/", 1) != 0)
// 		{
// 			tmp = ft_strjoin(path[i], "/");
// 			cmd_path = ft_strjoin(tmp, cmd);
// 			free(tmp);
// 			if (!access(cmd_path, F_OK))
// 				return (cmd_path);
// 		}
// 		free(cmd_path);
// 		cmd_path = NULL;
// 		i++;
// 	}
// 	return (NULL);
// }
