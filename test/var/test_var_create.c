/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_var_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:25:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 03:48:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_var_create_valid_variable(t_list **vars)
{
	(void)vars;
	printf("--- test_var_create_valid_variable ---\n");
	
	t_var *var = var_create(ft_strdup("TEST_KEY"), ft_strdup("test_value"), 1);
	
	if (var && var->key && var->value && 
		strcmp(var->key, "TEST_KEY") == 0 && 
		strcmp(var->value, "test_value") == 0 &&
		var->exported == 1)
	{
		printf("Expected: Valid var created\n");
		printf("Got: key=%s, value=%s, exported=%d\n", var->key, var->value, var->exported);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: Valid var, Got: NULL or wrong values\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_create_invalid_key(t_list **vars)
{
	(void)vars;
	printf("--- test_var_create_invalid_key ---\n");
	
	t_var *var = var_create(ft_strdup("123INVALID"), ft_strdup("value"), 0);
	
	if (var == NULL)
	{
		printf("Expected: NULL (invalid key)\n");
		printf("Got: NULL\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: NULL, Got: valid var (should reject invalid key)\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_create_with_empty_value(t_list **vars)
{
	(void)vars;
	printf("--- test_var_create_with_empty_value ---\n");
	
	t_var *var = var_create(ft_strdup("EMPTY_KEY"), ft_strdup(""), 1);
	
	if (var && var->value && strcmp(var->value, "") == 0)
	{
		printf("Expected: var with empty value\n");
		printf("Got: value='%s' (empty)\n", var->value);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: var with empty value\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}
