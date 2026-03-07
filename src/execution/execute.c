/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/07 05:50:03 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	count_tokens(t_token *token)
{
	int	total;

	total = 0;
	while (token)
	{
		total++;
		token = (t_token *)token->link.next;
	}
	return (total);
}

char	**build_argv(t_token *token)
{
	char	**argv;
	int		count;
	int		i;

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
	(void) node;
	(void) token;
	return (0);
	// char	*operator;

	// operator = (char *)token->link.content;
	// if (ft_strcmp(operator, "|") == 0)
	// 	return (execute_pipe(node->left, node->right));
	// else if (ft_strcmp(operator, "&&") == 0)
	// 	return (execute_and(node->left, node->right));
	// else if (ft_strcmp(operator, "||") == 0)
	// 	return (execute_or(node->left, node->right));
	// else if (ft_strcmp(operator, "<") == 0)
	// 	return (execute_redir_in(node->left, node->right));
	// else if (ft_strcmp(operator, ">") == 0)
	// 	return (execute_redir_out(node->left, node->right));
	// else if (ft_strcmp(operator, ">>") == 0)
	// 	return (execute_redir_append(node->left, node->right));
}

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "unset") == 0
	)
		return (TRUE);
	return (FALSE);
}

int	execute_external_cmd(t_list *vars, char **argv, char **envp)
{
	pid_t	pid;
	char	*cmd_path;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		cmd_path = find_cmd_path(vars, argv[0]);
		if (!cmd_path)
		{
			printf("Command not found: %s\n", argv[0]);
			ft_split_free(argv);
			exit(127);
		}
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror("execv failed");
			free(cmd_path);
			ft_split_free(argv);
			exit(1);
		}
		return (0);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	else
	{
		perror("fork failed");
		return (1);
	}
}

int	execute_builtin_cmd(t_list *vars, char **argv)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		return (builtin_cd(&vars, argv));
	else if (ft_strcmp(argv[0], "echo") == 0)
		return (builtin_echo(argv));
	else if (ft_strcmp(argv[0], "env") == 0)
		return (builtin_env(vars));
	// else if (ft_strcmp(argv[0], "exit") == 0)
	// 	return (builtin_exit());
	else if (ft_strcmp(argv[0], "export") == 0)
		return (builtin_export(&vars, argv));
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (builtin_pwd(vars));
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (builtin_unset(&vars, argv));
	return (TRUE);
}

int	execute_command(t_token *token, char **envp)
{
	t_list	*vars;
	char	**argv;

	argv = build_argv(token);
	vars = envp_to_lst(envp);
	if (is_builtin(argv[0]))
		execute_builtin_cmd(vars, argv);
	else
		execute_external_cmd(vars, argv, envp);
	ft_split_free(argv);
	lst_clear(&vars, var_clear);
	return (0);
}

int	execute(t_ast *node, char **envp)
{
	t_token	*token;

	if (!node)
		return (0);
	token = (t_token *)node->value;
	if (token && token->is_operator)
		return (execute_operator(node, token));
	else
		return (execute_command(token, envp));
}

// todo PIPE
// add in_child to execute args
// in_child default is false
// execute_pipe
// fork
// pass in_child as true
// execute_external_cmd receives in_child
// execute_external_cmd checks in_child
// if true -> execve directly (calls execute_in_parent)
// if false -> fork + execve (calls execute_in_child)
