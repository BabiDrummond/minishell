/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:58:08 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/09 16:40:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	execute_in_child(char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
	{
		perror("execv failed");
		exit(1);
	}
	return (0);
}

static int	execute_in_parent(char *path, char **argv, char **envp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, argv, envp) == -1)
		{
			perror("execv failed");
			exit(1);
		}
		return (0);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	else
	{
		perror("fork failed");
		return (1);
	}
}

int	execute_external_cmd(t_list *vars, char **argv, int is_child)
{
	char	**envp;
	char	*cmd_path;
	int		exit_status; 
	
	cmd_path = find_cmd_path(vars, argv[0]);
	if (!cmd_path)
	{
		printf("Command not found: %s\n", argv[0]);
		return(CMD_NOT_FOUND);
	}
	envp = lst_to_envp(vars);
	if (is_child)
		exit_status = execute_in_child(cmd_path, argv, envp);
	else
		exit_status = execute_in_parent(cmd_path, argv, envp);
	free(cmd_path);
	ft_split_free(envp);
	return (exit_status);
}
