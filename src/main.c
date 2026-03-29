/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 03:57:47 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_signal = 0;

int			main(int argc, char **argv, char **envp);
static void	init_ctx(t_shell *ctx, char **envp);
static void	main_loop(t_shell *ctx, struct termios *term);

int	main(int argc, char **argv, char **envp)
{
	struct termios	original_termios;
	t_shell			*ctx;
	(void)argc;
	(void)argv;
	
	tcgetattr(STDIN_FILENO, &original_termios);
	ctx = get_shell_ctx();
	init_ctx(ctx, envp);
	set_signals();
	main_loop(ctx, &original_termios);
	gc_free_all();
	return (ctx->exit_status);
}

static void	init_ctx(t_shell *ctx, char **envp)
{
	ctx->pid = getpid();
	ctx->vars = envp_to_lst(envp);
	ctx->exit_status = EXIT_SUCCESS;
	ctx->stdin_backup = -1;
	ctx->stdout_backup = -1;
	var_set(&ctx->vars, "SHLVL", 
			ft_itoa(ft_atoi(var_get_value(ctx->vars, "SHLVL")) + 1), TRUE);
}

static void	main_loop(t_shell *ctx, struct termios *term)
{
	char	**lexer_operators;
	char	**ast_operators;
	char	*prompt;
	t_head	*tokens;
	t_ast	*ast;
	
	lexer_operators = init_lexer_operators();
	ast_operators = init_ast_operators();
	prompt = NULL;
	tokens = NULL;
	while (1)
	{
		g_signal = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, term);
		prompt = readline("prompt> ");
		if (!prompt)
		{
			printf("exit\n");
			break ;
		}
		gc_add(prompt, free);
		add_history(prompt);
		if (get_trimmed_length(prompt) == 0)
			continue ;
		tokens = tokenize(prompt, lexer_operators);
		if (!tokens)
			continue;
		print_tokens(tokens);
		ast = parse(tokens, ast_operators);
		if (!ast)
			continue ;
		print_ast(ast, 0);
		if (collect_heredocs(ctx, ast))
			continue ;
		print_ast(ast, 0);
		ctx->exit_status = execute(ctx, ast, FALSE);
	}
}
