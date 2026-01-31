/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:32:52 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 20:26:16 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include <readline/readline.h>
#include <readline/history.h>

static void	handle_exit(char *prompt)
{
	if (strncmp(prompt, "exit", 5) == 0)
	{
		gc_free_all();
		free(prompt);
		exit(0);
	}
}

int	main(void)
{
	char		*prompt;
	t_string	**operators;
	t_list		*tokens;
	t_ast		*ast;

	operators = initialize_operators();
	prompt = NULL;
	tokens = NULL;
	while (1)
	{
		prompt = readline("prompt> ");
		tokens = tokenize(prompt, operators);
		handle_exit(prompt);
		print_tokens(tokens);
		ast = parse(tokens, operators);
		print_ast(ast, 0);
		free(prompt);
	}
	gc_free_all();
	return (0);
}
