/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:16:37 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 20:02:56 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

char	*get_delimiter(t_token *token)
{
	t_list	*parts;
	t_word	*word;

	if (token->is_operator)
		return (NULL);
	parts = (t_list *)token->link.content;
	word = (t_word *)lst_pop(parts);
	return ((char *)word->link.content);
}

void	heredoc_sigint_handler(int sig)
{
	(void) sig;
	exit(1);
}

static int	continue_with_child_process(int pipefd[2], const char *delimiter)
{
	char	*line;

	signal(SIGINT, heredoc_sigint_handler);
	close(pipefd[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			fprintf(stderr,
				"Warning: heredoc delimited by end-of-file (wanted `%s`)\n",
				delimiter);
			free(line);
			close(pipefd[1]);
			exit(0);
		}
		if (strcmp(line, delimiter) == 0)
		{
			free(line);
			close(pipefd[1]);
			exit(0);
		}
		write(pipefd[1], line, strlen(line));
		write(pipefd[1], "\n", 1);
	}
}

static int	continue_with_parent_process(pid_t pid,
	int pipefd[2], t_token *token)
{
	int	status;
	int	exit_code;

	waitpid(pid, &status, 0);
	close(pipefd[1]);
	exit_code = (status >> 8) & 0xFF;
	if (exit_code == 1)
	{
		close(pipefd[0]);
		return (1);
	}
	token->stdin_fd = pipefd[0];
	return (0);
}

int	collect_heredocs(t_ast *tokens)
{
	char	*delimiter;
	int		pipefd[2];
	pid_t	pid;

	if (tokens == NULL)
		return (0);
	if (collect_heredocs(tokens->left))
		return (1);
	if (collect_heredocs(tokens->right))
		return (1);
	if (should_collect_heredoc((t_token *)tokens->value))
	{
		delimiter = get_delimiter((t_token *)tokens->right->value);
		printf("Collecting heredoc until delimiter: %s\n", delimiter);
		pipe(pipefd);
		pid = fork();
		if (pid == 0)
			continue_with_child_process(pipefd, delimiter);
		return (continue_with_parent_process(pid, pipefd,
				(t_token *)tokens->value));
	}
	return (0);
}
