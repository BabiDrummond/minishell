/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_var_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:25:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 23:25:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_var_unset_existing_variable(t_list **vars)
{
	printf("--- test_var_unset_existing_variable ---\n");
	
	var_set(vars, ft_strdup("UNSET_TEST"), ft_strdup("value"), 1);
	var_unset(vars, "UNSET_TEST");
	
	t_var *var = var_get(*vars, "UNSET_TEST");
	
	if (var == NULL)
	{
		printf("Expected: NULL (variable removed)\n");
		printf("Got: NULL\n");
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: NULL, Got: variable still exists\n");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_var_unset_nonexistent_variable(t_list **vars)
{
	printf("--- test_var_unset_nonexistent_variable ---\n");
	
	// Isso não deveria crashar
	var_unset(vars, "NONEXISTENT_UNSET");
	
	printf("Expected: No crash\n");
	printf("Got: No crash\n");
	printf("\033[0;32m✓ PASS\033[0m\n");
}
