/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 18:17:51 by bmoreira         ###   ########.fr       */
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

	envp = ft_calloc(1, sizeof(char *));
	while (vars)
	{
		var = (t_var *) vars->content;
		*envp++ = ft_triple_join(var->key, "=", var->value);
		vars = vars->next;
	}
	return (envp);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	t_shell shell;
	char	*line;

	line = readline("minishell> ");
	printf("Comando digitado: %s\n", line);
	shell.vars = envp_to_lst(envp);
	shell.cmd_args = ft_split(line, ' ');
	printf("funcionou??????????????????????????\n");
	//builtin_env(shell.vars);
	//builtin_pwd(shell.vars);
	builtin_echo(&shell);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
