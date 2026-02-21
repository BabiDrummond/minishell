/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 00:42:30 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

// void	set_env_var(t_list **env, char *key, char *value)
// {
// 	t_list	**head;
// 	char	*var;

// 	var = ft_triple_join(key, "=", value);
// 	printf("var, key, value %s %s %s\n", var, key, value);
// 	head = env;
// 	if (get_env_var(*env, key) == NULL)
// 	{
// 		lst_add_back(env, lst_new(var));
// 		return ;
// 	}
// 	while (*env)
// 	{
// 		if (ft_strncmp((char *)(*env)->content, key, ft_strlen(key)) == 0)
// 		{
// 			printf("env key var len %s %s %s %zu\n", (char *) (*env)->content, key, var, ft_strlen(key));
// 			(*env)->content = var;
// 			return ;
// 		}
// 		*env = (*env)->next;
// 	}
// }

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

	envp = NULL;
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
	//info.cmd_args = ft_split(line, ' ');
	printf("funcionou??????????????????????????\n");
	//builtin_env(shell.vars);
	printf("get1: %s\n", var_get(shell.vars, "PATH"));
	var_set(&shell.vars, "PATH=Oi");
	printf("get2: %s\n", var_get(shell.vars, "PATH"));
	// printf("key %s\n", ((t_var *)shell.vars->content)->key);
	// ((t_var *)shell.vars->content)->key = "oi";
	// printf("key %s\n", ((t_var *)shell.vars->content)->key);
	// var = *(shell.vars);
	// printf("key %s\n", var->key);
	// printf("value %s\n", var->value);
	// printf("exported %d\n", var->exported);
	// var->exported = 2;
	// printf("exported %d", var->exported);
	//printf("PATH BEFORE: %s\n", get_env_var(info.env, "HALO"));
	//set_env_var(&info.env, "HALO", "ola");
	//printf("PATH AFTER: %s\n", get_env_var(info.env, "HALO"));
	//info.cmd_path = build_cmd_path(info.env_path, info.cmd_args[0]);
	//builtin_env(info.env);
	//builtin_pwd(info.env);
	//builtin_echo(&info);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
