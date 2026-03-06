/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:43:43 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 21:49:14 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void assert_export_result(char *test_name, char *var_name, char *expected_value, 
                         int expected_exit, char **args, t_list **vars)
{
    int exit_status = builtin_export(vars, args);
    char *actual_value = var_get_value(*vars, var_name);
    
    printf("--- %s ---\n", test_name);
    
    int value_matches = 0;
    if (expected_value == NULL && actual_value == NULL)
        value_matches = 1;
    else if (expected_value != NULL && actual_value != NULL && 
             strcmp(actual_value, expected_value) == 0)
        value_matches = 1;
    
    if (exit_status == expected_exit && value_matches)
    {
        printf("Expected exit: %d, Got: %d\n", expected_exit, exit_status);
        printf("Expected value: %s, Got: %s\n", 
               expected_value ? expected_value : "(null)", 
               actual_value ? actual_value : "(null)");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected exit: %d, Got: %d\n", expected_exit, exit_status);
        printf("Expected value: %s, Got: %s\n", 
               expected_value ? expected_value : "(null)", 
               actual_value ? actual_value : "(null)");
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_export_new_variable(t_list **vars)
{
    char *args[] = {"export", "TEST_VAR=hello", NULL};
    assert_export_result("test_export_new_variable", "TEST_VAR", "hello", 
                        EXIT_SUCCESS, args, vars);
}

void test_export_override_existing_variable(t_list **vars)
{
    char *args1[] = {"export", "TEST_VAR2=old", NULL};
    builtin_export(vars, args1);
    
    char *args2[] = {"export", "TEST_VAR2=new", NULL};
    assert_export_result("test_export_override_existing_variable", "TEST_VAR2", "new", 
                        EXIT_SUCCESS, args2, vars);
}

void test_export_empty_value(t_list **vars)
{
    char *args[] = {"export", "EMPTY_VAR=", NULL};
    assert_export_result("test_export_empty_value", "EMPTY_VAR", "", 
                        EXIT_SUCCESS, args, vars);
}

void test_export_invalid_name_with_special_char(t_list **vars)
{
    char *args[] = {"export", "INVALID@VAR=value", NULL};
    int exit_status = builtin_export(vars, args);
    
    printf("--- test_export_invalid_name_with_special_char ---\n");
    if (exit_status == EXIT_FAILURE)
    {
        printf("Expected exit: EXIT_FAILURE, Got: EXIT_FAILURE\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected exit: EXIT_FAILURE, Got: %d\n", exit_status);
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_export_invalid_name_starting_with_number(t_list **vars)
{
    char *args[] = {"export", "1INVALID=value", NULL};
    int exit_status = builtin_export(vars, args);
    
    printf("--- test_export_invalid_name_starting_with_number ---\n");
    if (exit_status == EXIT_FAILURE)
    {
        printf("Expected exit: EXIT_FAILURE, Got: EXIT_FAILURE\n");
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected exit: EXIT_FAILURE, Got: %d\n", exit_status);
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_export_multiple_variables(t_list **vars)
{
    char *args[] = {"export", "VAR1=value1", "VAR2=value2", "VAR3=value3", NULL};
    int exit_status = builtin_export(vars, args);
    
    char *val1 = var_get_value(*vars, "VAR1");
    char *val2 = var_get_value(*vars, "VAR2");
    char *val3 = var_get_value(*vars, "VAR3");
    
    printf("--- test_export_multiple_variables ---\n");
    
    if (exit_status == EXIT_SUCCESS && 
        val1 && strcmp(val1, "value1") == 0 &&
        val2 && strcmp(val2, "value2") == 0 &&
        val3 && strcmp(val3, "value3") == 0)
    {
        printf("Expected: All 3 variables created\n");
        printf("Got: VAR1=%s, VAR2=%s, VAR3=%s\n", val1, val2, val3);
        printf("\033[0;32m✓ PASS\033[0m\n");
    }
    else
    {
        printf("Expected: All 3 variables created\n");
        printf("Got: VAR1=%s, VAR2=%s, VAR3=%s\n", 
               val1 ? val1 : "(null)", 
               val2 ? val2 : "(null)", 
               val3 ? val3 : "(null)");
        printf("\033[0;31m✗ FAIL\033[0m\n");
    }
}

void test_export_variable_with_underscore(t_list **vars)
{
    char *args[] = {"export", "VALID_VAR_NAME=test", NULL};
    assert_export_result("test_export_variable_with_underscore", "VALID_VAR_NAME", "test", 
                        EXIT_SUCCESS, args, vars);
}
