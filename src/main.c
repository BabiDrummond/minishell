/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/29 01:55:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_signal = 0;

void	init_ctx(t_shell *ctx, char **envp)
{
	ctx->pid = getpid();
	ctx->vars = envp_to_lst(envp);
	ctx->exit_status = EXIT_SUCCESS;
	ctx->stdin_backup = -1;
	ctx->stdout_backup = -1;
}

int	get_trimmed_length(char *str)
{
	int	i;
	int	len;
	int	in_space;

	i = 0;
	len = 0;
	in_space = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			in_space = 1;
		else
		{
			if (in_space && len > 0)
				len++;
			in_space = 0;
			len++;
		}
		i++;
	}
	return (len);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	**lexer_operators;
	char	**ast_operators;
	char	*prompt;
	t_shell *ctx;
	t_head	*tokens;
	t_ast	*ast;
	struct termios	original_termios;
	tcgetattr(STDIN_FILENO, &original_termios);
	
	ctx = get_shell_ctx();
	init_ctx(ctx, envp);
	var_set(&ctx->vars, "SHLVL", ft_itoa(ft_atoi(var_get_value(ctx->vars, "SHLVL")) + 1), TRUE);
	lexer_operators = init_lexer_operators();
	ast_operators = init_ast_operators();
	prompt = NULL;
	tokens = NULL;
	set_signals();
	while (1)
	{
		g_signal = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
		prompt = readline("prompt> ");
		if (!prompt)
		{
			printf("exit\n");
			break ;
		}
		gc_add(prompt, free);
		if (get_trimmed_length(prompt) == 0)
			continue ;
		add_history(prompt);
		tokens = tokenize(prompt, lexer_operators);
		if (!tokens)
			continue;
		//print_tokens(tokens);
		ast = parse(tokens, ast_operators);
		if (!ast)
			continue ;
		//print_ast(ast, 0);
		if (collect_heredocs(ctx, ast))
			continue ;
		//print_ast(ast, 0);
		ctx->exit_status = execute(ctx, ast, FALSE);
	}
	gc_free_all();
	return (ctx->exit_status);
}
