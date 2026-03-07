/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:32:52 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/06 23:30:39 by bmoreira         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
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
		print_tokens(tokens);
		ast = parse(tokens, operators);
		if (!ast)
		{
			gc_free_all();
			continue ;
		}
		print_ast(ast, 0);
		if (collect_heredocs(ast))
		{
			gc_free_all();
			continue ;
		}
		print_ast(ast, 0);

		//execute(ast, envp);
		gc_free_all();
	}
	gc_free_all();
	return (0);
}
