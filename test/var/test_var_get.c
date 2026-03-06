/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_var_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:25:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 23:25:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_var_get_existing_variable(t_list **vars)
{
	printf("--- test_var_get_existing_variable ---\n");
	
	var_set(vars, ft_strdup("GET_TEST"), ft_strdup("get_value"), 1);
	t_var *var = var_get(*vars, "GET_TEST");
	
	if (var && var->key && strcmp(var->key, "GET_TEST") == 0 &&
		var->value && strcmp(var->value, "get_value") == 0)
	{
		printf("Expected: Found var with correct values\n");
		printf("Got: key=%s, value=%s\n", var->key, var->value);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: Found var, Got: NULL or wrong values\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_get_nonexistent_variable(t_list **vars)
{
	printf("--- test_var_get_nonexistent_variable ---\n");
	
	t_var *var = var_get(*vars, "NONEXISTENT_VAR");
	
	if (var == NULL)
	{
		printf("Expected: NULL\n");
		printf("Got: NULL\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: NULL, Got: var found (should not exist)\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_get_value_existing_variable(t_list **vars)
{
	printf("--- test_var_get_value_existing_variable ---\n");
	
	var_set(vars, ft_strdup("VALUE_TEST"), ft_strdup("test_value"), 0);
	char *value = var_get_value(*vars, "VALUE_TEST");
	
	if (value && strcmp(value, "test_value") == 0)
	{
		printf("Expected: test_value\n");
		printf("Got: %s\n", value);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: test_value, Got: %s\n", value ? value : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_get_value_nonexistent_variable(t_list **vars)
{
	printf("--- test_var_get_value_nonexistent_variable ---\n");
	
	char *value = var_get_value(*vars, "NONEXISTENT_VALUE");
	
	if (value == NULL)
	{
		printf("Expected: NULL\n");
		printf("Got: NULL\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: NULL, Got: %s\n", value);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}
