/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/07 20:43:13 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	info.cmd_args = ft_split(line, ' ');
	info.cmd_path = build_cmd_path(info.path, info.cmd_args[0]);
	execute_echo(&info);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
