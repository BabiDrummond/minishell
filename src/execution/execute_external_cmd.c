/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:58:08 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/14 21:32:43 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	execute_in_child(char *path, char **argv, char **envp)
{
	execve(path, argv, envp);
	perror(argv[0]);
	if (errno == ENOENT)
		exit(CMD_NOT_FOUND);
	else if (errno == EACCES)
		exit(PERMISSION_DENIED);
	else
		exit(EXIT_FAILURE);
}

static int	execute_in_parent(char *path, char **argv, char **envp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execute_in_child(path, argv, envp);
	if (pid < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

int	execute_external_cmd(t_shell *ctx, char **argv, int is_child)
{
	char	**envp;
	char	*cmd_path;
	int		exit_status;

	cmd_path = find_cmd_path(ctx->vars, argv[0]);
	if (!cmd_path)
	{
		printf("Command not found: %s\n", argv[0]);
		return (CMD_NOT_FOUND);
	}
	envp = lst_to_envp(ctx->vars);
	if (is_child)
		execute_in_child(cmd_path, argv, envp);
	else
		exit_status = execute_in_parent(cmd_path, argv, envp);
	free(cmd_path);
	ft_split_free(envp);
	return (exit_status);
}
