/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:33:22 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 21:59:09 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "expansion.h"

int			process_redirects(t_shell *ctx, t_list *redirs, int is_child);
static void	save_fds(t_shell *ctx, t_list *redirs, int is_child);
static int	open_fd(t_shell *ctx, t_redir *redir, char **target);
static int	redir_fd(t_redir *redir, int fd);
void		restore_fds(t_shell *ctx, int is_child);

int	process_redirects(t_shell *ctx, t_list *redirs, int is_child)
{
	char	**expanded;
	t_list	*redir;
	int		fd;

	fd = -1;
	redir = redirs;
	save_fds(ctx, redirs, is_child);
	while (redir)
	{
		expanded = expand_redirect(ctx, redir->content);
		if (!expanded)
			return (EXIT_FAILURE);
		fd = open_fd(ctx, redir->content, expanded);
		if (fd == -1 && printf("no such file or directory\n"))
			return (EXIT_FAILURE);
		if (redir_fd(redir->content, fd) == -1)
		{
			close(fd);
			return (EXIT_FAILURE);
		}
		close(fd);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}

static void	save_fds(t_shell *ctx, t_list *redirs, int is_child)
{
	if (!is_child && redirs)
	{
		ctx->stdin_backup = dup(STDIN_FILENO);
		ctx->stdout_backup = dup(STDOUT_FILENO);
	}
}

static int	open_fd(t_shell *ctx, t_redir *redir, char **target)
{
	int		fd;

	fd = -1;
	if (ft_strcmp(redir->type, "<<") == 0)
		fd = redirect_heredoc(target);
	else if (ft_strcmp(redir->type, "<") == 0)
		fd = open(target[0], O_RDONLY);
	else if (ft_strcmp(redir->type, ">") == 0)
		fd = open(target[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strcmp(redir->type, ">>") == 0)
		fd = open(target[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

static int	redir_fd(t_redir *redir, int fd)
{
	if (ft_strcmp(redir->type, "<") == 0
		|| ft_strcmp(redir->type, "<<") == 0)
		return (dup2(fd, STDIN_FILENO));
	else if (ft_strcmp(redir->type, ">") == 0
		|| ft_strcmp(redir->type, ">>") == 0)
		return (dup2(fd, STDOUT_FILENO));
	return (-1);
}

void	restore_fds(t_shell *ctx, int is_child)
{
	if (!is_child)
	{
		if (ctx->stdin_backup != -1)
		{
			dup2(ctx->stdin_backup, STDIN_FILENO);
			close(ctx->stdin_backup);
			ctx->stdin_backup = -1;
		}
		if (ctx->stdout_backup != -1)
		{
			dup2(ctx->stdout_backup, STDOUT_FILENO);
			close(ctx->stdout_backup);
			ctx->stdout_backup = -1;
		}
	}
}
