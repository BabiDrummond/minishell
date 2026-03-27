/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:16:37 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 16:49:02 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int				collect_heredocs(t_ast *ast);
static t_word	*collect_input(t_word *delimiter);

int	collect_heredocs(t_ast *ast)
{
	t_exec_node	*node;
	t_list		*redirs;
	t_redir		*redir;

	if (ast == NULL)
		return (EXIT_SUCCESS);
	if (collect_heredocs(ast->left))
		return (EXIT_FAILURE);
	if (collect_heredocs(ast->right))
		return (EXIT_FAILURE);
	node = (t_exec_node *) ast->value;
	redirs = node->redirs;
	while (redirs)
	{
		redir = (t_redir *) redirs->content;
		if (ft_strcmp(redir->type, "<<") == 0)
			redir->target = collect_input(redir->target);
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
}

static t_word	*collect_input(t_word *delimiter)
{
	t_word	*words;
	char	*line;

	words = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("Warning: heredoc delimited by end-of-file "
				"(wanted `%s')\n", (char *)delimiter->link.content);
			break ;
		}
		gc_add(line, free);
		if (line && ft_strcmp(line, delimiter->link.content) == 0)
			break ;
		lst_add_back((t_list **)&words, (t_list *)create_word(line,
				ft_strlen(line), delimiter->quote_state));
	}
	return (words);
}
