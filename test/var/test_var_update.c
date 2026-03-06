/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_var_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:25:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 23:25:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_var_update_changes_value_and_export_status(t_list **vars)
{
	printf("--- test_var_update_changes_value_and_export_status ---\n");
	
	// Criar variável inicial
	var_set(vars, ft_strdup("UPDATE_TEST"), ft_strdup("old"), 0);
	
	// Criar nova var para update
	t_var *new_var = var_create(ft_strdup("UPDATE_TEST"), ft_strdup("new"), 1);
	var_update(vars, new_var);
	
	t_var *var = var_get(*vars, "UPDATE_TEST");
	
	if (var && var->value && strcmp(var->value, "new") == 0 && var->exported == 1)
	{
		printf("Expected: value=new, exported=1\n");
		printf("Got: value=%s, exported=%d\n", var->value, var->exported);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: value=new, exported=1\n");
		printf("Got: value=%s, exported=%d\n", 
			var && var->value ? var->value : "(null)", 
			var ? var->exported : -1);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}
