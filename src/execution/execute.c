/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/19 17:37:07 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// int	print_error_and_return(t_shell *ctx, char *error_msg, int exit_status)
// {
// 	perror(error_msg);
// 	ctx->exit_status = exit_status;
// 	return (ctx->exit_status);
// }

int	count_word_parts(t_word *words)
{
	int	i;

	i = 0;
	while (words)
	{
		i++;
		words = (t_word *) words->link.next;
	}
	return (i);
}

char	*build_target(t_word *words)
{
	t_word	*word;
	char	*target;
	int		word_parts;
	int		word_len;
	int		i;

	i = 0;
	word = words;
	word_parts = count_word_parts(words);
	target = ft_calloc(word_parts + 1, sizeof(char));
	while(word)
	{
		word_len = ft_strlen((char *)word);
		ft_memcpy(target + i, (char *)word, word_len);
		i += word_len;
		word = (t_word *) words->link.next;
	}
	return (target);
}

int	open_fd(t_redir *redir)
{
	char	*target;

	target = build_target(redir->target);
	if (ft_strcmp(redir->type, "<") == 0)
		return (open(target, O_RDONLY));
	else if (ft_strcmp(redir->type, ">") == 0)
		return (open(target, O_WRONLY, O_CREAT, O_TRUNC));
	else if (ft_strcmp(redir->type, ">>") == 0)
		return (open(target, O_WRONLY, O_CREAT, O_APPEND));
	return (-1);
}

int	process_redirects(t_list *redirs)
{
	t_list	*node;
	int		fd;

	fd = -1;
	node = redirs;
	while (node)
	{
		fd = open_fd(node->content);
		if (fd == -1)
			return (EXIT_FAILURE);
		node->next;
	}
}

// 1. iterar pela lista de redirs
// 2. se redir_in: open readonly
// 3. se redir_out: open wronly, creat, trunc
// 4. se redir_append: open wronly, creat, append

int	execute(t_shell *ctx, t_ast *ast, int is_child)
{
	t_exec_node	*node;

	if (!ast)
		return (EXIT_SUCCESS);
	node = (t_exec_node *) ast->value;
	if (node->argv && node->type == NODE_CMD)
		return (execute_cmd(ctx, node, is_child));
	return (execute_operator(ctx, ast, node, is_child));
}
