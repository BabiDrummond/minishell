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
