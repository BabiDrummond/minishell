/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:33:22 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/24 01:10:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int			process_redirects(t_shell *ctx, t_list *redirs, int is_child);
static int	open_fd(t_redir *redir);
static int	redir_fd(t_redir *redir, int fd);
void		restore_fds(t_shell *ctx, int is_child);
static char	*build_string(t_word *words);

int	process_redirects(t_shell *ctx, t_list *redirs, int is_child)
{
	t_list	*redir;
	int		fd;

	fd = -1;
	redir = redirs;
	if (!is_child && redirs)
	{
		ctx->stdin_backup = dup(STDIN_FILENO);
		ctx->stdout_backup = dup(STDOUT_FILENO);
	}
	while (redir)
	{
		fd = open_fd(redir->content);
		if (fd == -1)
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

static int	open_fd(t_redir *redir)
{
	char	*target;
	int		fd;

	fd = -1;
	target = build_string(redir->target);
	if (ft_strcmp(redir->type, "<") == 0)
		fd = open(target, O_RDONLY);
	else if (ft_strcmp(redir->type, ">") == 0)
		fd = open(target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strcmp(redir->type, ">>") == 0)
		fd = open(target, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(target);
	return (fd);
}

static int	redir_fd(t_redir *redir, int fd)
{
	if (ft_strcmp(redir->type, "<") == 0)
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

static char	*build_string(t_word *words)
{
	t_word	*word;
	char	*string;

	word = words;
	string = ft_strdup("");
	while (word)
	{
		string = ft_strjoin_free(string, word->link.content, TRUE, FALSE);
		word = (t_word *) word->link.next;
	}
	return (string);
}
