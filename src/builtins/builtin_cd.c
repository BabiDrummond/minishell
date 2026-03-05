/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:34:24 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/27 22:14:32 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_cd(t_list **vars, char **args)
{
	char	new_pwd[1024];
	char	*old_pwd;
	char	*path;

	path = *(args + 1);
	if (!path || ft_strcmp(path, "~") == 0)
		path = var_get_value(*vars, "HOME");
	if (!path && printf("cd: HOME not set\n"))
		return ;
	if (chdir(path) == -1 && printf("cd: %s: no such file or directory\n", path))
		return ;
	old_pwd = var_get_value(*vars, "PWD");
	var_set(vars, ft_strdup("OLD_PWD"), ft_strdup(old_pwd), TRUE);
	if (getcwd(new_pwd, sizeof(new_pwd)) == -1)
		return ;
	var_set(vars, ft_strdup("PWD"), ft_strdup(new_pwd), TRUE);
}

// cd (empty args) / cd ~ => changes to home
// cd . => stays on current dir
// cd .. => changes to previous dir
// cd / (one or more slashes) => changes to root
// cd /(one or more slashes)dirname => changes to folder in root
// cd path => check if exists. if yes, change to path. if not, shows error msg