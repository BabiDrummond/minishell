/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_extract_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:20:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 22:39:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_extract_key_with_equal_sign(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_key_with_equal_sign ---\n");
	
	char *key = extract_key("KEY=value");
	
	if (key && strcmp(key, "KEY") == 0)
	{
		printf("Expected: KEY\n");
		printf("Got: %s\n", key);
		printf("\033[0;32m✓ PASS\033[0m\n");
		free(key);
	}
	else
	{
		printf("Expected: KEY, Got: %s\n", key ? key : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
		if (key)
			free(key);
	}
}

void test_extract_key_without_equal_sign(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_key_without_equal_sign ---\n");
	
	char *key = extract_key("KEY");
	
	if (key && strcmp(key, "KEY") == 0)
	{
		printf("Expected: KEY\n");
		printf("Got: %s\n", key);
		printf("\033[0;32m✓ PASS\033[0m\n");
		free(key);
	}
	else
	{
		printf("Expected: KEY, Got: %s\n", key ? key : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
		if (key)
			free(key);
	}
}

void test_extract_key_with_empty_value(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_key_with_empty_value ---\n");
	
	char *key = extract_key("KEY=");
	
	if (key && strcmp(key, "KEY") == 0)
	{
		printf("Expected: KEY\n");
		printf("Got: %s\n", key);
		printf("\033[0;32m✓ PASS\033[0m\n");
		free(key);
	}
	else
	{
		printf("Expected: KEY, Got: %s\n", key ? key : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
		if (key)
			free(key);
	}
}

void test_extract_key_with_multiple_equals(t_list **vars)
{
	(void)vars;
	printf("--- test_extract_key_with_multiple_equals ---\n");
	
	char *key = extract_key("KEY=value=another");
	
	if (key && strcmp(key, "KEY") == 0)
	{
		printf("Expected: KEY\n");
		printf("Got: %s\n", key);
		printf("\033[0;32m✓ PASS\033[0m\n");
		free(key);
	}
	else
	{
		printf("Expected: KEY, Got: %s\n", key ? key : "(null)");
		printf("\033[0;31m✗ FAIL\033[0m\n");
		if (key)
			free(key);
	}
}
