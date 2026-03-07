/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/06 23:39:26 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **build_argv(t_token *token)
{
	char    **argv;
	int     count;
	int     i;

	count = count_tokens(token);
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	i = 0;
	while (token)
	{
		argv[i] = join_token_parts(token);
		i++;
		token = (t_token *)token->link.next;
	}
	argv[i] = NULL;
	return (argv);
}

int	execute_operator(t_ast *node, t_token *token)
{
	char	*operator;

	operator = (char *)token->link.content;
	if (ft_strcmp(operator, "|") == 0)
		return (execute_pipe(node->left, node->right));
	else if (ft_strcmp(operator, "&&") == 0)
		return (execute_and(node->left, node->right));
	else if (ft_strcmp(operator, "||") == 0)
		return (execute_or(node->left, node->right));
	else if (ft_strcmp(operator, "<") == 0)
		return (execute_redir_in(node->left, node->right));
	else if (ft_strcmp(operator, ">") == 0)
		return (execute_redir_out(node->left, node->right));
	else if (ft_strcmp(operator, ">>") == 0)
		return (execute_redir_append(node->left, node->right));
}

int	execute_command(t_token *token, char **envp)
{
	char	*argv;

	argv = build_argv(token);
	 
	pid_t pid = fork();
	if (pid == 0)
	{
		char *command_path = find_cmd_path(argv[0]);
		if (!command_path)
		{
			fprintf(stderr, "Command not found: %s\n", argv[0]);
			exit(127);
		}

		if(execve(command_path, argv, envp) == -1)
		{
			perror("execv failed");
			free(command_path);
			exit(1);
		}
		return (0);
	}
	else if (pid > 0)
	{
		int status;
		waitpid(pid, &status, 0);
		free(argv);
		return (WEXITSTATUS(status));
	}
	else
	{
		perror("fork failed");
		free(argv);
		return (1);
	}
	return (0);
}

int	execute(t_ast *node, char **envp)
{
	t_token *token;

	if (!node)
		return (0);
	token = (t_token *)node->value;
	if (token && token->is_operator)
		return (execute_operator(node, token));
	else
		return (execute_command(token, envp));
}
