/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:05:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 22:05:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_env_shows_exported_variables(t_list **vars)
{
    // Criar uma variável exportada
    char *args[] = {"export", "TEST_ENV_VAR=exported_value", NULL};
    builtin_export(vars, args);
    
    printf("--- test_env_shows_exported_variables ---\n");
    printf("Running env (check if TEST_ENV_VAR=exported_value appears):\n");
    
    int exit_status = builtin_env(*vars);
    
    // Verificar se a variável está na lista
    char *value = var_get_value(*vars, "TEST_ENV_VAR");
    
    if (exit_status == EXIT_SUCCESS && value && strcmp(value, "exported_value") == 0)
    {
        printf("Expected: SUCCESS and variable exported\n");
        printf("Got: SUCCESS\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: SUCCESS, Got: %d\n", exit_status);
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_env_returns_success(t_list **vars)
{
    printf("--- test_env_returns_success ---\n");
    
    int exit_status = builtin_env(*vars);
    
    if (exit_status == EXIT_SUCCESS)
    {
        printf("Expected: SUCCESS\n");
        printf("Got: SUCCESS\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: SUCCESS, Got: %d\n", exit_status);
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_env_with_empty_value(t_list **vars)
{
    // Criar variável com valor vazio
    char *args[] = {"export", "EMPTY_ENV=", NULL};
    builtin_export(vars, args);
    
    printf("--- test_env_with_empty_value ---\n");
    printf("Running env (check if EMPTY_ENV= appears):\n");
    
    int exit_status = builtin_env(*vars);
    
    char *value = var_get_value(*vars, "EMPTY_ENV");
    
    if (exit_status == EXIT_SUCCESS && value && strcmp(value, "") == 0)
    {
        printf("Expected: Variable with empty value shown\n");
        printf("Got: SUCCESS\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: SUCCESS, Got: %d\n", exit_status);
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_env_does_not_show_unexported_variables(t_list **vars)
{
	printf("--- test_env_does_not_show_unexported_variables ---\n");
	
	// Criar variável NÃO exportada
	var_set(vars, ft_strdup("NOT_EXPORTED_VAR"), ft_strdup("secret"), 0);
	
	// Redirecionar stdout para capturar output
	FILE *tmp = tmpfile();
	int saved_stdout = dup(STDOUT_FILENO);
	dup2(fileno(tmp), STDOUT_FILENO);
	
	builtin_env(*vars);
	
	// Restaurar stdout
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	
	// Ler output
	rewind(tmp);
	char buffer[4096] = {0};
	fread(buffer, 1, sizeof(buffer) - 1, tmp);
	fclose(tmp);
	
	// Verificar se NOT_EXPORTED_VAR NÃO aparece no output
	int found = (strstr(buffer, "NOT_EXPORTED_VAR") != NULL);
	
	if (!found)
	{
		printf("Expected: NOT_EXPORTED_VAR not shown\n");
		printf("Got: Variable not found in env output\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: NOT_EXPORTED_VAR not shown\n");
		printf("Got: Variable found in env output (FAIL)\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
	
	// Limpar
	char *unset_args[] = {"unset", "NOT_EXPORTED_VAR", NULL};
	builtin_unset(vars, unset_args);
}
