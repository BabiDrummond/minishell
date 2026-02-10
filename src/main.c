/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/09 19:31:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_shell *info)
{	
	char	*str;
	int		n_option;
	int		i;

	i = 0;
	n_option = 0;
	while (ft_strncmp(info->cmd_args[++i], "-n", 2) == 0)
		n_option++;
	str = ft_join_split(info->cmd_args + i, " ");
	printf("%s", str);
	if (!n_option)
		printf("\n");
}

char	*builtin_pwd(t_shell *info)
{
	char	*pwd;
	int		i;

	i = 0;
	pwd = NULL;
	while (info->envp[i])
	{
		if (ft_strncmp(info->envp[i], "PWD", 3) == 0)
			pwd = info->envp[i] + 4;
		i++;
	}
	printf("%s\n", pwd);
	return (pwd);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	t_shell info;
	char	*line;

	line = readline("minishell> ");
	printf("Comando digitado: %s\n", line);
	info.envp = envp;
	info.env_path = get_env_path(envp);
	info.cmd_args = ft_split(line, ' ');
	info.cmd_path = build_cmd_path(info.env_path, info.cmd_args[0]);
	info.curr_dir = builtin_pwd(&info);
	//execute_echo(&info);
	printf("curr dir: %s\n", info.curr_dir);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
