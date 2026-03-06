/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:17:31 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 20:20:02 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_cd_to_valid_directory(t_list **vars)
{
	printf("--- test_cd_to_valid_directory ---\n");
	
	char *args[] = {"cd", "/tmp", NULL};
	int exit_status = builtin_cd(vars, args);
	
	char *pwd = var_get_value(*vars, "PWD");
	
	if (exit_status == EXIT_SUCCESS && pwd && strcmp(pwd, "/tmp") == 0)
	{
		printf("Expected: SUCCESS and PWD=/tmp\n");
		printf("Got: SUCCESS and PWD=%s\n", pwd);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: SUCCESS and PWD=/tmp\n");
		printf("Got: exit_status=%d, PWD=%s\n", exit_status, pwd ? pwd : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_cd_without_arguments_goes_to_home(t_list **vars)
{
	printf("--- test_cd_without_arguments_goes_to_home ---\n");
	
	char *home = var_get_value(*vars, "HOME");
	if (!home)
	{
		printf("HOME not set, skipping test\n");
		printf("\033[0;33m⊘ SKIP\033[0m\n");
		return;
	}
	
	char *args[] = {"cd", NULL};
	int exit_status = builtin_cd(vars, args);
	
	char *pwd = var_get_value(*vars, "PWD");
	
	if (exit_status == EXIT_SUCCESS && pwd && strcmp(pwd, home) == 0)
	{
		printf("Expected: SUCCESS and PWD=%s\n", home);
		printf("Got: SUCCESS and PWD=%s\n", pwd);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: SUCCESS and PWD=%s\n", home);
		printf("Got: exit_status=%d, PWD=%s\n", exit_status, pwd ? pwd : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_cd_with_tilde_goes_to_home(t_list **vars)
{
	printf("--- test_cd_with_tilde_goes_to_home ---\n");
	
	char *home = var_get_value(*vars, "HOME");
	if (!home)
	{
		printf("HOME not set, skipping test\n");
		printf("\033[0;33m⊘ SKIP\033[0m\n");
		return;
	}
	
	char *args[] = {"cd", "~", NULL};
	int exit_status = builtin_cd(vars, args);
	
	char *pwd = var_get_value(*vars, "PWD");
	
	if (exit_status == EXIT_SUCCESS && pwd && strcmp(pwd, home) == 0)
	{
		printf("Expected: SUCCESS and PWD=%s\n", home);
		printf("Got: SUCCESS and PWD=%s\n", pwd);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: SUCCESS and PWD=%s\n", home);
		printf("Got: exit_status=%d, PWD=%s\n", exit_status, pwd ? pwd : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_cd_with_dash_goes_to_oldpwd(t_list **vars)
{
	printf("--- test_cd_with_dash_goes_to_oldpwd ---\n");
	
	// Primeiro, cd para /tmp
	char *args1[] = {"cd", "/tmp", NULL};
	builtin_cd(vars, args1);
	
	// Depois, cd para /
	char *args2[] = {"cd", "/", NULL};
	builtin_cd(vars, args2);
	
	// Agora OLDPWD deve ser /tmp
	char *oldpwd = var_get_value(*vars, "OLDPWD");
	if (!oldpwd)
	{
		printf("OLDPWD not set, test failed\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
		return;
	}
	
	// cd -
	char *args3[] = {"cd", "-", NULL};
	int exit_status = builtin_cd(vars, args3);
	
	char *pwd = var_get_value(*vars, "PWD");
	
	if (exit_status == EXIT_SUCCESS && pwd && strcmp(pwd, "/tmp") == 0)
	{
		printf("Expected: SUCCESS and PWD=/tmp\n");
		printf("Got: SUCCESS and PWD=%s\n", pwd);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: SUCCESS and PWD=/tmp\n");
		printf("Got: exit_status=%d, PWD=%s\n", exit_status, pwd ? pwd : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_cd_to_nonexistent_directory_fails(t_list **vars)
{
	printf("--- test_cd_to_nonexistent_directory_fails ---\n");
	
	char *args[] = {"cd", "/nonexistent_directory_12345", NULL};
	int exit_status = builtin_cd(vars, args);
	
	if (exit_status == EXIT_FAILURE)
	{
		printf("Expected: FAILURE\n");
		printf("Got: FAILURE\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: FAILURE, Got: %d\n", exit_status);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_cd_without_home_variable_fails(t_list **vars)
{
	printf("--- test_cd_without_home_variable_fails ---\n");
	
	// Salvar HOME original
	char *original_home = var_get_value(*vars, "HOME");
	char *home_copy = NULL;
	if (original_home)
		home_copy = strdup(original_home);
	
	// Remover HOME
	char *unset_args[] = {"unset", "HOME", NULL};
	builtin_unset(vars, unset_args);
	
	// Tentar cd sem argumentos
	char *args[] = {"cd", NULL};
	int exit_status = builtin_cd(vars, args);
	
	// Restaurar HOME
	if (home_copy)
		var_set(vars, ft_strdup("HOME"), home_copy, 1);
	
	if (exit_status == EXIT_FAILURE)
	{
		printf("Expected: FAILURE\n");
		printf("Got: FAILURE\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: FAILURE, Got: %d\n", exit_status);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_cd_updates_oldpwd(t_list **vars)
{
	printf("--- test_cd_updates_oldpwd ---\n");
	
	// cd para /tmp
	char *args1[] = {"cd", "/tmp", NULL};
	builtin_cd(vars, args1);
	
	char *pwd_before = var_get_value(*vars, "PWD");
	char *pwd_copy = pwd_before ? strdup(pwd_before) : NULL;
	
	// cd para /
	char *args2[] = {"cd", "/", NULL};
	int exit_status = builtin_cd(vars, args2);
	
	char *oldpwd = var_get_value(*vars, "OLDPWD");
	
	if (exit_status == EXIT_SUCCESS && oldpwd && pwd_copy && 
		strcmp(oldpwd, pwd_copy) == 0)
	{
		printf("Expected: OLDPWD=%s\n", pwd_copy);
		printf("Got: OLDPWD=%s\n", oldpwd);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: OLDPWD=%s\n", pwd_copy ? pwd_copy : "(null)");
		printf("Got: OLDPWD=%s\n", oldpwd ? oldpwd : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
	
	if (pwd_copy)
		free(pwd_copy);
}

void test_cd_dash_without_oldpwd_fails(t_list **vars)
{
	printf("--- test_cd_dash_without_oldpwd_fails ---\n");
	
	// Salvar OLDPWD original
	char *original_oldpwd = var_get_value(*vars, "OLDPWD");
	char *oldpwd_copy = NULL;
	if (original_oldpwd)
		oldpwd_copy = strdup(original_oldpwd);
	
	// Remover OLDPWD
	char *unset_args[] = {"unset", "OLDPWD", NULL};
	builtin_unset(vars, unset_args);
	
	// Tentar cd -
	char *args[] = {"cd", "-", NULL};
	int exit_status = builtin_cd(vars, args);
	
	// Restaurar OLDPWD
	if (oldpwd_copy)
		var_set(vars, ft_strdup("OLDPWD"), oldpwd_copy, 1);
	
	if (exit_status == EXIT_FAILURE)
	{
		printf("Expected: FAILURE\n");
		printf("Got: FAILURE\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: FAILURE, Got: %d\n", exit_status);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_cd_with_too_many_arguments_fails(t_list **vars)
{
	printf("--- test_cd_with_too_many_arguments_fails ---\n");
	
	char *args[] = {"cd", "/tmp", "/home", NULL};
	int exit_status = builtin_cd(vars, args);
	
	if (exit_status == EXIT_FAILURE)
	{
		printf("Expected: FAILURE (too many arguments)\n");
		printf("Got: FAILURE\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: FAILURE, Got: %d\n", exit_status);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}
