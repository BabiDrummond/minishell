/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 03:50:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_signal = 0;

static void	handle_exit(char *prompt)
{
	if (ft_strcmp(prompt, "exit") == 0)
	{
		gc_free_all();
		gc_set_current_scope(GC_SCOPE_GLOBAL);
		gc_free_all();
		exit(0);
	}
}

void	init_ctx(t_shell *ctx, char **envp)
{
	ctx->pid = getpid();
	ctx->vars = envp_to_lst(envp);
	ctx->exit_status = EXIT_SUCCESS;
	ctx->should_exit = FALSE;
	ctx->stdin_backup = -1;
	ctx->stdout_backup = -1;
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	**lexer_operators;
	char	**ast_operators;
	char	*prompt;
	t_shell ctx;
	t_head	*tokens;
	t_ast	*ast;
	
	init_ctx(&ctx, envp);
	lexer_operators = init_lexer_operators();
	ast_operators = init_ast_operators();
	prompt = NULL;
	tokens = NULL;
	set_signals();
	while (1)
	{
		g_signal = 0;
		prompt = readline("prompt> ");
		if (!prompt)
		{
			printf("exit\n");
			break ;
		}
		add_history(prompt);
		gc_add(prompt, free);
		if (strlen(prompt) == 0)
			continue ;
		gc_set_current_scope(GC_SCOPE_FUNCTION);
		tokens = tokenize(prompt, lexer_operators);
		handle_exit(prompt);
		print_tokens(tokens);
		
		ast = parse(tokens, ast_operators);
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

		ctx.exit_status = execute(&ctx, ast, FALSE);
		gc_free_all();
	}
	gc_set_current_scope(GC_SCOPE_GLOBAL);
	gc_free_all();
	return (ctx.exit_status);
}

// DEPOIS do parser, ANTES do execute
// Percorrer árvore
// Para cada nó, percorrer lista de redirs
// Para cada heredoc, ler input do usuário até EOF
// Substituir conteúdo do EOF com conteúdo lido na lista de redirs