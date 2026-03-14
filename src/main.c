/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/14 20:20:23 by bmoreira         ###   ########.fr       */
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

void	init_shell(t_shell *shell, char **envp)
{
	shell->pid = getpid();
	shell->vars = envp_to_lst(envp);
	shell->exit_status = EXIT_SUCCESS;
	shell->stdin_backup = dup(STDIN_FILENO);
	shell->stdout_backup = dup(STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	**operators;
	char	*prompt;
	t_shell shell;
	t_head	*tokens;
	t_ast	*ast;
	
	init_shell(&shell, envp);
	operators = initialize_operators();
	prompt = NULL;
	tokens = NULL;
	while (1)
	{
		signal(SIGINT, signal_handler);
		prompt = readline("prompt> ");
		//prompt = ft_strdup("echo oiiii");
		if (!prompt)
			continue ;
		gc_add(prompt, free);
		if (strlen(prompt) == 0)
			continue ;
		gc_set_current_scope(GC_SCOPE_FUNCTION);
		tokens = tokenize(prompt, operators);
		handle_exit(prompt);
		print_tokens(tokens);
		ast = parse(tokens, operators);
		if (!ast)
		{
			gc_free_all();
			continue ;
		}
		//print_ast(ast, 0);
		// if (collect_heredocs(ast))
		// {
		// 	gc_free_all();
		// 	continue ;
		// }
		// print_ast(ast, 0);

		//shell.exit_status = execute(&shell, ast, FALSE);
		gc_free_all();
	}
	ft_split_free(operators);
	lst_clear(&shell.vars, var_clear);
	gc_free_all();
	return (shell.exit_status);
}
