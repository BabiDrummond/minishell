/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 22:59:53 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_var	*var_create(char *var_content, int exported)
{
	char	**split;
	t_var	*var;

	var = ft_calloc(1, sizeof(t_var));
	split = ft_split(var_content, '=');
	var->key = ft_strdup(split[0]);
	var->value = ft_strdup(split[1]);
	var->exported = exported;
	ft_split_free(split);
	return (var);
}

// t_list	*envp_to_lst(char **envp)
// {
// 	t_list	*vars;
// 	t_var	*var;
// 	int		i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		var = var_create(envp[i++], TRUE);
// 		//printf("key %s value %s exp %d\n", var->key, var->value, var->exported);
// 		lst_add_back(&vars, lst_new(var));
// 	}
// 	printf("i: %d\n", i);
// 	return (vars);
// }

void	envp_to_lst(t_list **vars, char **envp)
{
	t_var	*var;
	int		i;

	i = 0;
	*vars = NULL;
	while (envp[i])
	{
		var = var_create(envp[i++], TRUE);
		//printf("key %s value %s exp %d\n", var->key, var->value, var->exported);
		lst_add_back(vars, lst_new(var));
	}
	printf("i: %d\n", i);
}

char	**lst_to_envp(t_list *vars)
{
	t_var	*var;
	char	**envp;

	envp = NULL;
	while(vars)
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
	//t_var	*var;
	//t_list	*vars;
	char	*line;

	line = readline("minishell> ");
	printf("Comando digitado: %s\n", line);
	//shell.vars = envp_to_lst(envp);
	envp_to_lst(&shell.vars, envp);
	//info.cmd_args = ft_split(line, ' ');
	printf("funcionou??????????????????????????\n");
	//builtin_env(&shell.vars);
	printf("key %s\n", ((t_var *)shell.vars->content)->key);
	((t_var *)shell.vars->content)->key = "oi";
	printf("key %s\n", ((t_var *)shell.vars->content)->key);
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
