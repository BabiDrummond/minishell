/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:58:08 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 00:05:11 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int			execute_external_cmd(t_shell *ctx, char **argv, int is_child);
static int	execute_in_parent(char *path, char **argv, char **envp);
static void	execute_in_child(char *path, char **argv, char **envp);

int	execute_external_cmd(t_shell *ctx, char **argv, int is_child)
{
	char	**envp;
	char	*cmd_path;

	cmd_path = find_cmd_path(ctx->vars, argv[0]);
	if (!cmd_path)
		return (print_error(ft_replace("Command not found: %s\n", "%s",
					argv[0]), CMD_NOT_FOUND));
	envp = lst_to_envp(ctx->vars);
	if (is_child)
		execute_in_child(cmd_path, argv, envp);
	else
		ctx->exit_status = execute_in_parent(cmd_path, argv, envp);
	return (ctx->exit_status);
}

static int	execute_in_parent(char *path, char **argv, char **envp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
		execute_in_child(path, argv, envp);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

static void	execute_in_child(char *path, char **argv, char **envp)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(path, argv, envp);
	perror(argv[0]);
	if (errno == ENOENT)
		exit(CMD_NOT_FOUND);
	else if (errno == EACCES)
		exit(PERMISSION_DENIED);
	else
		exit(EXIT_FAILURE);
}
