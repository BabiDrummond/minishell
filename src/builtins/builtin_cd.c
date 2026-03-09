/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:34:24 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/09 16:45:09 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(t_list **vars, char **argv)
{
	char	new_pwd[1024];
	char	*old_pwd;
	char	*dir;

	dir = argv[1];
	if (ft_split_size(argv) > 2 && printf("cd: too many arguments\n"))
		return (EXIT_FAILURE);
	if (!argv[1] || ft_strcmp(argv[1], "~") == 0)
		dir = var_get_value(*vars, "HOME");
	if (!dir && printf("cd: HOME not set\n"))
		return (EXIT_FAILURE);
	if (argv[1] && ft_strcmp(argv[1], "-") == 0)
		dir = var_get_value(*vars, "OLDPWD");
	if (!dir && printf("cd: OLDPWD not set\n"))
		return (EXIT_FAILURE);
	if (chdir(dir) == -1 && printf("cd: %s: No such file or directory\n", dir))
		return (EXIT_FAILURE);
	old_pwd = var_get_value(*vars, "PWD");
	var_set(vars, ft_strdup("OLDPWD"), ft_strdup(old_pwd), TRUE);
	if (getcwd(new_pwd, sizeof(new_pwd)) != NULL)
		var_set(vars, ft_strdup("PWD"), ft_strdup(new_pwd), TRUE);
	return (EXIT_SUCCESS);
}
