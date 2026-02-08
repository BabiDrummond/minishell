/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 01:38:57 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_echo(t_shell *info)
{	
	char	*str;
	int		n_option;
	int		i;

	i = 1;
	n_option = 0;
	str = NULL;
	while (ft_strnstr(info->cmd_args[i++], "-n", 2))
		n_option++;
	str = ft_join_split(info->cmd_args + n_option + 1, " ");
	printf("%s", str);
	if (!n_option)
		printf("\n");
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
	info.path = get_env_path(envp);
	info.cmd_args = ft_split(line, ' ');
	info.cmd_path = build_cmd_path(info.path, info.cmd_args[0]);
	execute_echo(&info);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
