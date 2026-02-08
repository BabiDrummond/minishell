/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 00:20:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_echo(t_shell *info, int argc)
{	
	char	*str;
	int		n_option;

	n_option = 0;
	if (ft_strnstr(info->cmd_args[1], "-n", 2))
		n_option = 1;
	str = ft_reverse_split(info->cmd_args, argc, ' ');
	printf("%s", str);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell info;
	char	*line;
	(void) argc;
	(void) argv;

	line = readline("minishell> ");
	printf("Comando digitado: %s\n", line);
	info.envp = envp;
	info.path = get_env_path(envp);
	info.cmd_args = argv + 1;
	//info.cmd_path = build_cmd_path(info.path, info.cmd_args[0]);
	execute_echo(&info, argc);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
