/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 22:41:29 by bmoreira         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	t_shell shell;
	// char	**envp_copy;
	// char	*line;

	// line = readline("minishell> ");
	// printf("Comando digitado: %s\n", line);
	shell.vars = envp_to_lst(envp);
	// shell.args = ft_split(line, ' ');
	// envp_copy = lst_to_envp(shell.vars);
	lst_clear(&shell.vars, var_clear);
	// ft_split_free(&shell.args);
	return (0);
}
