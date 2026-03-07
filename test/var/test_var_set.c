/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_var_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:25:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 23:25:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_var_set_new_variable(t_list **vars)
{
	printf("--- test_var_set_new_variable ---\n");
	
	int result = var_set(vars, ft_strdup("NEW_VAR"), ft_strdup("new_value"), 1);
	char *value = var_get_value(*vars, "NEW_VAR");
	
	if (result == EXIT_SUCCESS && value && strcmp(value, "new_value") == 0)
	{
		printf("Expected: SUCCESS and value=new_value\n");
		printf("Got: result=%d, value=%s\n", result, value);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: SUCCESS and value=new_value\n");
		printf("Got: result=%d, value=%s\n", result, value ? value : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_set_override_existing(t_list **vars)
{
	printf("--- test_var_set_override_existing ---\n");
	
	var_set(vars, ft_strdup("OVERRIDE_VAR"), ft_strdup("old_value"), 0);
	var_set(vars, ft_strdup("OVERRIDE_VAR"), ft_strdup("new_value"), 1);
	
	char *value = var_get_value(*vars, "OVERRIDE_VAR");
	t_var *var = var_get(*vars, "OVERRIDE_VAR");
	
	if (value && strcmp(value, "new_value") == 0 && var && var->exported == 1)
	{
		printf("Expected: value=new_value, exported=1\n");
		printf("Got: value=%s, exported=%d\n", value, var->exported);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: value=new_value, exported=1\n");
		printf("Got: value=%s, exported=%d\n", 
			value ? value : "(null)", var ? var->exported : -1);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_set_with_empty_value(t_list **vars)
{
	printf("--- test_var_set_with_empty_value ---\n");
	
	var_set(vars, ft_strdup("EMPTY_VAR"), ft_strdup(""), 1);
	char *value = var_get_value(*vars, "EMPTY_VAR");
	
	if (value && strcmp(value, "") == 0)
	{
		printf("Expected: empty string\n");
		printf("Got: empty string\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: empty string, Got: %s\n", value ? value : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}
