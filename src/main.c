/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/07 20:59:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*reverse_split(char **split, char c)
{
	char	*str;
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	str = str_dup("");
	while(split[len])
		len++;
	while (split[i])
	{
		tmp = str;
		str = ft_strjoin(split[i], str);
		free(tmp);
		if (i != len - 1)
		{
			tmp = str;
			str = ft_strjoin(str, " ");
			free(tmp);
		}
	}
	return (str);
}

void	execute_echo(t_shell *info)
{	
	int	i;
	int	n_option;

	n_option = 0;
	if (ft_strncmp(info->cmd_args[1], "-n", 2) == 0)
		n_option = 1;
	i = n_option;
	while (info->cmd_args[i++])
		printf("%s ", info->cmd_args[i]);
	if (!n_option)
		printf("\n");
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
	info.cmd_args = ft_split(line, ' ');
	info.cmd_path = build_cmd_path(info.path, info.cmd_args[0]);
	execute_echo(&info);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
