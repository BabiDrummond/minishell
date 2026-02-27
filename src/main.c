/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:32:52 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/22 04:59:07 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_exit(char *prompt)
{
	if (strncmp(prompt, "exit", 5) == 0)
	{
		gc_free_all();
		free(prompt);
		exit(0);
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

char *find_comand_in_path(char *command)
{
	char *path_env = getenv("PATH");
	if (!path_env)
		return NULL;

	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char full_path[1024];
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return strdup(full_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}

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

static size_t	get_token_parts_length(t_token *token)
{
	size_t	total;
	t_word	*part;

	total = 0;
	part = (t_word *)((t_head *)token->link.content)->first;
	while (part)
	{
		total += strlen((char *)part->link.content);
		part = (t_word *)part->link.next;
	}
	return (total);
}

char	*join_token_parts(t_token *token)
{
	size_t	total_len;
	char	*result;
	size_t	i;
	t_word	*part;
	size_t	len;

	total_len = get_token_parts_length(token);
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);

	i = 0;
	part = (t_word *)((t_head *)token->link.content)->first;
	while (part)
	{
		len = strlen((char *)part->link.content);
		memcpy(result + i, part->link.content, len);
		i += len;
		part = (t_word *)part->link.next;
	}

	result[i] = '\0';
	return (result);
}

char **build_argv(t_token *token)
{
	int count;
	char **argv;
	int i;

	count = count_tokens(token);
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return NULL;

	i = 0;
	while (token)
	{
		argv[i] = join_token_parts(token);
		i++;
		token = (t_token *)token->link.next;
	}
	argv[i] = NULL;

	return argv;
}

int	execute(t_ast *tokens, char **envp)
{
	if (tokens == NULL)
		return (0);
	if (execute(tokens->left, envp))
		return (1);
	if (execute(tokens->right, envp))
		return (1);
    
    t_token *token = (t_token *)tokens->value;
	
    if (token && token->is_operator)
    {
        char *operator = token->link.content;
        char *symbol = operator;
        printf("Operator \"%s\" is not implemented!\n", symbol);
        return (0);
	}
	
	char **argv = build_argv(token);
    
    pid_t pid = fork();
    if (pid == 0)
    {
		char *command_path = find_comand_in_path(argv[0]);
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

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char		*prompt;
	char	**operators;
	t_head		*tokens;
	t_ast		*ast;

	operators = initialize_operators();
	prompt = NULL;
	tokens = NULL;
	while (1)
	{
		signal(SIGINT, signal_handler);
		prompt = readline("prompt> ");
		if (!prompt)
			continue ;
		gc_add(prompt, free);
		if (strlen(prompt) == 0)
			continue ;
		gc_set_current_scope(GC_SCOPE_FUNCTION);
		tokens = tokenize(prompt, operators);
		handle_exit(prompt);
		// print_tokens(tokens);
		ast = parse(tokens, operators);
		if (!ast)
		{
			gc_free_all();
			continue ;
		}
		// print_ast(ast, 0);
		if (collect_heredocs(ast))
		{
			gc_free_all();
			continue ;
		}
		// print_ast(ast, 0);

		execute(ast, envp);
		gc_free_all();
	}
	gc_free_all();
	return (0);
}
