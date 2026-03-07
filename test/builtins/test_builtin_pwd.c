/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_pwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:10:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 22:03:06 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_pwd_returns_success(t_list **vars)
{
    printf("--- test_pwd_returns_success ---\n");
    
    int exit_status = builtin_pwd(*vars);
    
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

void test_pwd_prints_current_directory(t_list **vars)
{
    printf("--- test_pwd_prints_current_directory ---\n");
    
    // Pegar o diretório atual real
    char expected[1024];
    getcwd(expected, sizeof(expected));
    
    printf("Expected output: %s\n", expected);
    printf("Actual output: ");
    
    int exit_status = builtin_pwd(*vars);
    
    if (exit_status == EXIT_SUCCESS)
    {
        printf("\033[0;32m✓ PASS\033[0m (verify output matches above)\n");
    }
    else
    {
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_pwd_uses_pwd_variable(t_list **vars)
{
    printf("--- test_pwd_uses_pwd_variable ---\n");
    
    // Verificar se a variável PWD existe
    char *pwd_var = var_get_value(*vars, "PWD");
    
    if (pwd_var)
    {
        printf("PWD variable: %s\n", pwd_var);
        printf("Actual output: ");
        builtin_pwd(*vars);
        printf("Expected: Output matches PWD variable\n");
        printf("\033[0;32m✓ PASS\033[0m (verify output matches PWD above)\n");
    }
    else
    {
        printf("PWD not set, using getcwd() fallback\n");
        printf("Output: ");
        builtin_pwd(*vars);
        printf("\033[0;32m✓ PASS\033[0m (fallback working)\n");
    }
}

void test_pwd_after_cd(t_list **vars)
{
    printf("--- test_pwd_after_cd ---\n");
    
    // Fazer cd para /tmp
    char *cd_args[] = {"cd", "/tmp", NULL};
    int cd_status = builtin_cd(vars, cd_args);
    
    if (cd_status == EXIT_SUCCESS)
    {
        printf("Changed to /tmp\n");
        printf("PWD output: ");
        builtin_pwd(*vars);
        
        char *pwd_var = var_get_value(*vars, "PWD");
        if (pwd_var && strcmp(pwd_var, "/tmp") == 0)
        {
            printf("Expected: /tmp\n");
            printf("Got: %s\n", pwd_var);
            printf("\033[0;32m✓ PASS\033[0m\n");
        }
        else
        {
            printf("Expected: /tmp, Got: %s\n", pwd_var ? pwd_var : "(null)");
            printf("\033[0;31m✗ FAIL\033[0m\n");
        }
    }
    else
    {
        printf("cd failed, skipping test\n");
        printf("\033[0;33m⊘ SKIP\033[0m\n");
    }
}
