/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:20:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 22:39:46 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_is_valid_key_with_valid_name(t_list **vars)
{
	(void)vars;
	printf("--- test_is_valid_key_with_valid_name ---\n");
	
	int result = is_valid_key("VALID_NAME");
	
	if (result == 1)
	{
		printf("Expected: 1 (valid)\n");
		printf("Got: %d\n", result);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: 1, Got: %d\n", result);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_is_valid_key_with_underscore(t_list **vars)
{
	(void)vars;
	printf("--- test_is_valid_key_with_underscore ---\n");
	
	int result = is_valid_key("_VALID_NAME");
	
	if (result == 1)
	{
		printf("Expected: 1 (valid)\n");
		printf("Got: %d\n", result);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: 1, Got: %d\n", result);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_is_valid_key_starting_with_number(t_list **vars)
{
	(void)vars;
	printf("--- test_is_valid_key_starting_with_number ---\n");
	
	int result = is_valid_key("123INVALID");
	
	if (result == 0)
	{
		printf("Expected: 0 (invalid)\n");
		printf("Got: %d\n", result);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: 0, Got: %d\n", result);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_is_valid_key_with_special_char(t_list **vars)
{
	(void)vars;
	printf("--- test_is_valid_key_with_special_char ---\n");
	
	int result = is_valid_key("INVALID@NAME");
	
	if (result == 0)
	{
		printf("Expected: 0 (invalid)\n");
		printf("Got: %d\n", result);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: 0, Got: %d\n", result);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_is_valid_key_with_dash(t_list **vars)
{
	(void)vars;
	printf("--- test_is_valid_key_with_dash ---\n");
	
	int result = is_valid_key("INVALID-NAME");
	
	if (result == 0)
	{
		printf("Expected: 0 (invalid)\n");
		printf("Got: %d\n", result);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: 0, Got: %d\n", result);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}

void test_is_valid_key_empty_string(t_list **vars)
{
	(void)vars;
	printf("--- test_is_valid_key_empty_string ---\n");
	
	int result = is_valid_key("");
	
	if (result == 0)
	{
		printf("Expected: 0 (invalid)\n");
		printf("Got: %d\n", result);
		printf("\033[0;32m✓ PASS\033[0m\n");
	}
	else
	{
		printf("Expected: 0, Got: %d\n", result);
		printf("\033[0;31m✗ FAIL\033[0m\n");
	}
}
