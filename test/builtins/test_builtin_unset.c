/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_unset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:43:55 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 22:00:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void assert_unset_result(char *test_name, char *var_name, int should_exist, 
                         int expected_exit, char **args, t_list **vars)
{
    int exit_status = builtin_unset(vars, args);
    char *actual_value = var_get_value(*vars, var_name);
    
    printf("--- %s ---\n", test_name);
    
    int test_passed = 0;
    if (exit_status == expected_exit)
    {
        if (should_exist && actual_value != NULL)
            test_passed = 1;
        else if (!should_exist && actual_value == NULL)
            test_passed = 1;
    }
    
    if (test_passed)
    {
        printf("Expected exit: %d, Got: %d\n", expected_exit, exit_status);
        printf("Variable %s: %s\n", var_name, 
               actual_value ? actual_value : "(unset - correct)");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected exit: %d, Got: %d\n", expected_exit, exit_status);
        printf("Expected var %s: %s, Got: %s\n", var_name,
               should_exist ? "exists" : "unset",
               actual_value ? actual_value : "(null)");
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_unset_existing_variable(t_list **vars)
{
    // Primeiro cria uma variável
    char *args1[] = {"export", "TO_UNSET=value", NULL};
    builtin_export(vars, args1);
    
    // Depois faz unset
    char *args2[] = {"unset", "TO_UNSET", NULL};
    assert_unset_result("test_unset_existing_variable", "TO_UNSET", 0, 
                       EXIT_SUCCESS, args2, vars);
}

void test_unset_nonexistent_variable(t_list **vars)
{
    char *args[] = {"unset", "DOES_NOT_EXIST", NULL};
    int exit_status = builtin_unset(vars, args);
    
    printf("--- test_unset_nonexistent_variable ---\n");
    if (exit_status == EXIT_SUCCESS)
    {
        printf("Expected: SUCCESS (bash doesn't fail on nonexistent vars)\n");
        printf("Got: SUCCESS\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: SUCCESS, Got: FAILURE\n");
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_unset_without_arguments(t_list **vars)
{
    char *args[] = {"unset", NULL};
    int exit_status = builtin_unset(vars, args);
    
    printf("--- test_unset_without_arguments ---\n");
    if (exit_status == EXIT_SUCCESS)
    {
        printf("Expected: SUCCESS (bash returns 0 for unset without args)\n");
        printf("Got: SUCCESS\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: SUCCESS, Got: FAILURE\n");
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_unset_invalid_name(t_list **vars)
{
    char *args[] = {"unset", "INVALID@NAME", NULL};
    int exit_status = builtin_unset(vars, args);
    
    printf("--- test_unset_invalid_name ---\n");
    if (exit_status == EXIT_FAILURE)
    {
        printf("Expected: FAILURE (invalid name)\n");
        printf("Got: FAILURE\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: FAILURE, Got: %d\n", exit_status);
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_unset_multiple_variables(t_list **vars)
{
    // Criar 3 variáveis
    char *args1[] = {"export", "VAR_A=a", "VAR_B=b", "VAR_C=c", NULL};
    builtin_export(vars, args1);
    
    // Unset 2 delas
    char *args2[] = {"unset", "VAR_A", "VAR_C", NULL};
    int exit_status = builtin_unset(vars, args2);
    
    char *val_a = var_get_value(*vars, "VAR_A");
    char *val_b = var_get_value(*vars, "VAR_B");
    char *val_c = var_get_value(*vars, "VAR_C");
    
    printf("--- test_unset_multiple_variables ---\n");
    
    if (exit_status == EXIT_SUCCESS && 
        val_a == NULL && 
        val_b != NULL && strcmp(val_b, "b") == 0 &&
        val_c == NULL)
    {
        printf("Expected: VAR_A and VAR_C unset, VAR_B remains\n");
        printf("Got: VAR_A=%s, VAR_B=%s, VAR_C=%s\n", 
               val_a ? val_a : "(unset)", 
               val_b ? val_b : "(unset)",
               val_c ? val_c : "(unset)");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: VAR_A and VAR_C unset, VAR_B='b'\n");
        printf("Got: VAR_A=%s, VAR_B=%s, VAR_C=%s\n", 
               val_a ? val_a : "(null)", 
               val_b ? val_b : "(null)",
               val_c ? val_c : "(null)");
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_unset_with_valid_and_invalid_names(t_list **vars)
{
    // Criar variáveis
    char *args1[] = {"export", "VALID1=v1", "VALID2=v2", NULL};
    builtin_export(vars, args1);
    
    // Tentar unset com nome válido e inválido
    char *args2[] = {"unset", "VALID1", "INVALID@", "VALID2", NULL};
    int exit_status = builtin_unset(vars, args2);
    
    char *val1 = var_get_value(*vars, "VALID1");
    char *val2 = var_get_value(*vars, "VALID2");
    
    printf("--- test_unset_with_valid_and_invalid_names ---\n");
    
    // Bash continua processando e retorna erro no final
    if (exit_status == EXIT_FAILURE && val1 == NULL && val2 == NULL)
    {
        printf("Expected: Both valid vars unset, exit=FAILURE\n");
        printf("Got: VALID1=%s, VALID2=%s, exit=FAILURE\n", 
               val1 ? val1 : "(unset)", 
               val2 ? val2 : "(unset)");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: Both valid vars unset, exit=FAILURE\n");
        printf("Got: VALID1=%s, VALID2=%s, exit=%d\n", 
               val1 ? val1 : "(null)", 
               val2 ? val2 : "(null)",
               exit_status);
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}
