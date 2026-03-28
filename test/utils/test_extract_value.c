/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_extract_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:20:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 21:45:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_extract_value_with_equal_sign(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_value_with_equal_sign ---\n");
	
	char *value = extract_value("KEY=value");
	
	if (value && strcmp(value, "value") == 0)
	{
		printf("Expected: value\n");
		printf("Got: %s\n", value);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: value, Got: %s\n", value ? value : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_extract_value_without_equal_sign(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_value_without_equal_sign ---\n");
	
	char *value = extract_value("KEY");
	
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

void test_extract_value_with_empty_value(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_value_with_empty_value ---\n");
	
	char *value = extract_value("KEY=");
	
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

void test_extract_value_with_multiple_equals(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_value_with_multiple_equals ---\n");
	
	char *value = extract_value("KEY=value=another");
	
	if (value && strcmp(value, "value=another") == 0)
	{
		printf("Expected: value=another\n");
		printf("Got: %s\n", value);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: value=another, Got: %s\n", value ? value : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}
