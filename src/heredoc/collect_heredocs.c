/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:16:37 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/19 18:52:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	collect_heredocs(t_ast *tokens)
{
	if (tokens == NULL)
		return (0);
	if (collect_heredocs(tokens->left))
		return (1);
	if (collect_heredocs(tokens->right))
		return (1);

	t_exec_node *node = (t_exec_node *) tokens->value;
	t_list *redirs = node->redirs;

	while(redirs)
	{
		t_redir *redir = (t_redir *) redirs->content;
		if (ft_strcmp(redir->type, "<<") == 0)
		{
			t_word *delimiter = redir->target;
			t_word *words = NULL;
			int error = 0;
			while (1)
			{
				char *line = readline("> ");
				if (!line)
				{
					// TODO: talvez nao possa usar essa funcao
					fprintf(stderr,
						"Warning: heredoc delimited by end-of-file (wanted `%s`)\n",
						(char*) delimiter->link.content);
					return (1);
				}
				if (ft_strcmp(line, (char*) delimiter->link.content) == 0)
				{
					free(line);
					break;
				}
				lst_add_back((t_list**) &words, (t_list*)create_word(line, ft_strlen(line), delimiter->quote_state));
			}
			redir->target = words;
		}
		redirs = redirs->next;
	}
	return (0);
}
