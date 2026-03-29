/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 17:58:52 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_signal = 0;
int			main(int argc, char **argv, char **envp);
static void	init_ctx(t_shell *ctx, char **envp);
static void	main_loop(t_shell *ctx, struct termios *term);
static char	*read_input(struct termios *term);
static void	process_input(t_shell *ctx, char *prompt,
				char **lexer_ops, char **ast_ops);

int	main(int argc, char **argv, char **envp)
{
	struct termios	original_termios;
	t_shell			*ctx;

	tcgetattr(STDIN_FILENO, &original_termios);
	ctx = get_shell_ctx();
	init_ctx(ctx, envp);
	set_signals();
	gc_set_current_scope(GC_SCOPE_FUNCTION);
	main_loop(ctx, &original_termios);
	gc_free_all();
	(void)argc;
	(void)argv;
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

	lexer_operators = init_lexer_operators();
	ast_operators = init_ast_operators();
	prompt = NULL;
	while (1)
	{
		prompt = read_input(term);
		if (!prompt)
			break ;
		process_input(ctx, prompt, lexer_operators, ast_operators);
	}
	gc_free_all();
}

static char	*read_input(struct termios *term)
{
	char	*prompt;

	g_signal = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, term);
	prompt = readline("prompt> ");
	if (!prompt)
	{
		printf("exit\n");
		return (NULL);
	}
	gc_add(prompt, free);
	if (get_trimmed_length(prompt) > 0)
		add_history(prompt);
	return (prompt);
}

static void	process_input(t_shell *ctx, char *prompt,
		char **lexer_ops, char **ast_ops)
{
	t_head	*tokens;
	t_ast	*ast;

	tokens = NULL;
	if (get_trimmed_length(prompt) == 0)
		return ;
	tokens = tokenize(prompt, lexer_ops);
	if (!tokens)
		return ;
	//print_tokens(tokens);
	ast = parse(tokens, ast_ops);
	if (!ast)
		return ;
	//print_ast(ast, 0);
	if (collect_heredocs(ctx, ast))
		return ;
	//print_ast(ast, 0);
	ctx->exit_status = execute(ctx, ast, FALSE);
}
