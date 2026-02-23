/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 03:13:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*envp_to_lst(char **envp)
{
	t_list	*vars;
	t_var	*var;
	int		i;

	i = 0;
	vars = NULL;
	while (envp[i])
	{
		var = var_create(envp[i++], TRUE);
		lst_add_back(&vars, lst_new(var));
	}
	return (vars);
}

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
	//char	**envp_copy;
	// char	*line;

	// line = readline("minishell> ");
	// printf("Comando digitado: %s\n", line);
	shell.vars = envp_to_lst(envp);
	// shell.args = ft_split(line, ' ');
	var_set(&shell.vars, "SOA8jid-j=", TRUE);
	printf("var: %s\n", var_get_value(shell.vars, "SOA8jidj"));
	var_set(&shell.vars, "CACHORRO=animal", TRUE);
	var_set(&shell.vars, "GATO=animal", TRUE);
	builtin_export(&shell.vars, "PINGU=PENGUIM EFEITO=BUTTERFLY ASIJAD0-=3984 mais=um w= eesse PATH=NOVOOOOOOOO");
	//envp_copy = lst_to_envp(shell.vars);
	//ft_matrix_print(envp_copy);
	builtin_env(shell.vars);
	printf("eesse: %s\n", var_get_value(shell.vars, "eesse"));
	printf("cachorro: %s\n", var_get_value(shell.vars, "CACHORRO"));
	printf("gato: %s\n", var_get_value(shell.vars, "GATO"));
	builtin_unset(&shell.vars, "CACHORRO");
	printf("cachorro: %s\n", var_get_value(shell.vars, "CACHORRO"));
	printf("gato: %s\n", var_get_value(shell.vars, "GATO"));
	builtin_env(shell.vars);
	builtin_unset(&shell.vars, "CACHORRO GATO");
	printf("cachorro: %s\n", var_get_value(shell.vars, "CACHORRO"));
	printf("gato: %s\n", var_get_value(shell.vars, "GATO"));
	builtin_unset(&shell.vars, "CACHORRO GATO AAASND-O");
	printf("cachorro: %s\n", var_get_value(shell.vars, "CACHORRO"));
	printf("gato: %s\n", var_get_value(shell.vars, "GATO"));
	builtin_unset(&shell.vars, "");
	//builtin_pwd(shell.vars);
	//builtin_echo(shell.args + 1);
	//execve(info.cmd_path, shell.args, shell.env);
	//free(line);
	lst_clear(&shell.vars, var_clear);
	// ft_split_free(&shell.args);
	return (0);
}
