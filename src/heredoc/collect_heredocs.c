/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:16:37 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/29 20:19:48 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int				collect_heredocs(t_shell *ctx, t_ast *ast);
static t_word	*build_delimiter(t_word *words);
static t_word	*collect_input(t_word *delimiter);
static char		*read_heredoc_line(t_word *delimiter, t_word **words);

int	collect_heredocs(t_shell *ctx, t_ast *ast)
{
	t_exec_node	*node;
	t_list		*redirs;
	t_redir		*redir;

	if (ast == NULL)
		return (EXIT_SUCCESS);
	if (collect_heredocs(ctx, ast->left)
		|| collect_heredocs(ctx, ast->right))
		return (EXIT_FAILURE);
	node = (t_exec_node *) ast->value;
	redirs = node->redirs;
	while (redirs)
	{
		if (g_signal == SIGINT)
			return (exit_status(ctx, CTRL_C));
		redir = (t_redir *) redirs->content;
		if (ft_strcmp(redir->type, "<<") == 0)
		{
			redir->target = collect_input(build_delimiter(redir->target));
			if (redir->target == NULL)
				return (EXIT_FAILURE);
		}
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
}

static t_word	*build_delimiter(t_word *words)
{
	t_word			*word;
	char			*string;
	t_quote_state	quote_state;

	word = words;
	string = ft_strdup("");
	quote_state = QUOTE_NONE;
	while (word)
	{
		string = ft_strjoin(string, word->link.content);
		if (word->quote_state == QUOTE_SINGLE
			|| word->quote_state == QUOTE_DOUBLE)
			quote_state = QUOTE_DOUBLE;
		word = (t_word *) word->link.next;
	}
	return (create_word(string, ft_strlen(string), quote_state));
}

static t_word	*collect_input(t_word *delimiter)
{
	t_word	*words;
	char	*line;

	words = NULL;
	while (1)
	{
		line = read_heredoc_line(delimiter, &words);
		if (!line)
			break ;
		lst_add_back((t_list **)&words,
			(t_list *)create_word(line,
				ft_strlen(line), delimiter->quote_state));
	}
	return (words);
}

static char	*read_heredoc_line(t_word *delimiter, t_word **words)
{
	char	*line;

	line = readline("> ");
	if (!line)
	{
		printf("Warning: heredoc delimited by end-of-file "
			"(wanted `%s')\n", (char *)delimiter->link.content);
		return (NULL);
	}
	gc_add(line, free);
	if (g_signal == SIGINT)
		return (NULL);
	if (ft_strcmp(line, delimiter->link.content) == 0)
	{
		if (*words == NULL)
			lst_add_back((t_list **)words,
				(t_list *)create_word(ft_strdup(""), 0,
					delimiter->quote_state));
		return (NULL);
	}
	return (line);
}
