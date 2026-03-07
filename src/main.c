/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/07 00:34:40 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_envp(t_list *vars)
{
	t_var	*var;
	char	**envp;
	char	**start;

	envp = ft_calloc(lst_size(vars) + 1, sizeof(char *));
	start = envp;
	while (vars)
	{
		var = (t_var *) vars->content;
		if (var && var->exported)
			*envp++ = ft_triple_join(var->key, "=", var->value);
		vars = vars->next;
	}
	return (start);
}

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
	// (void) argc;
	// (void) argv;
	// t_shell shell;
	// // char	**envp_copy;
	// // char	*line;
	// // line = readline("minishell> ");
	// // printf("Comando digitado: %s\n", line);
	// shell.vars = envp_to_lst(envp);
	// // shell.args = ft_split(line, ' ');
	// // envp_copy = lst_to_envp(shell.vars);
	// lst_clear(&shell.vars, var_clear);
	// // ft_split_free(&shell.args);
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

		// execute(ast, envp);
		gc_free_all();
	}
	gc_free_all();
	return (0);
}
