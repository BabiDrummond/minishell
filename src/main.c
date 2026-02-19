/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:09:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 18:04:49 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env_var(t_list **env, char *key, char *value)
{
	t_list	**head;
	char	*var;

	var = ft_strjoin(key, "=");
	var = ft_strjoin_free(var, value, TRUE, FALSE);
	printf("var, key, value %s %s %s\n", var, key, value);
	head = env;
	if (get_env_var(*env, key) == NULL)
		lst_add_back(env, lst_new(var));
	else
	{
		printf("var already exists\n");
		while (*env)
		{
			if (ft_strncmp((char *)(*env)->content, key, ft_strlen(key)) == 0)
			{
				printf("env key var len %s %s %s %zu\n", (char *) (*env)->content, key, var, ft_strlen(key));
				(*env)->content = var;
				return ;
			}
			*env = (*env)->next;
		}
	}
}

t_list	*set_env(t_list **env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		lst_add_back(env, lst_new(envp[i++]));
	return (*env);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	t_shell info;
	t_list	*env;
	char	*line;

	env = NULL;
	line = readline("minishell> ");
	printf("Comando digitado: %s\n", line);
	info.env = set_env(&env, envp);
	info.cmd_args = ft_split(line, ' ');
	printf("PATH BEFORE: %s\n", get_env_var(info.env, "PATH"));
	set_env_var(&info.env, "PATH", "ola");
	printf("PATH AFTER: %s\n", get_env_var(info.env, "PATH"));
	//info.cmd_path = build_cmd_path(info.env_path, info.cmd_args[0]);
	//builtin_env(info.env);
	//builtin_pwd(info.env);
	//builtin_echo(&info);
	//execve(info.cmd_path, info.cmd_args, info.envp);
	//free(line);
	return (0);
}
