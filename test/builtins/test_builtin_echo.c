/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:20:37 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 21:40:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void assert_echo_output(char *test_name, char *expected, char **args)
{
    int saved_stdout = dup(STDOUT_FILENO);
    FILE *temp = tmpfile();
    int temp_fd = fileno(temp);
    
    fflush(stdout);
    dup2(temp_fd, STDOUT_FILENO);
    
    builtin_echo(args);
    fflush(stdout);
    
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    
    rewind(temp);
    
    char buffer[1024] = {0};
    char *result = fgets(buffer, sizeof(buffer), temp);
    
    printf("--- %s ---\n", test_name);
    
    if (expected == NULL)
    {
        if (result == NULL)
        {
            printf("Expected: (empty)\nGot: (empty)\n");
            printf("\033[0;32m✓ PASS\033[0m\n");
        }
        else
        {
            printf("Expected: (empty)\nGot: %s\n", buffer);
            printf("\033[0;31m✗ FAIL\033[0m\n");
        }
    }
    else
    {
        if (result != NULL && strcmp(buffer, expected) == 0)
        {
            printf("Expected: %s\nGot: %s\n", expected, buffer);
            printf("\033[0;32m✓ PASS\033[0m\n");
        }
        else
        {
            printf("Expected: %s\nGot: %s\n", expected, result ? buffer : "(empty)");
            printf("\033[0;31m✗ FAIL\033[0m\n");
        }
    }
    
    fclose(temp);
}
void test_echo_with_empty_args_should_print_new_line(void)
{
    char *args[] = {"echo", NULL};
    assert_echo_output("test_echo_with_empty_args_should_print_new_line", "\n", args);
}

void test_echo_with_n_option_and_empty_args_should_print_nothing(void)
{
    char *args[] = {"echo", "-n", NULL};
    assert_echo_output("test_echo_with_n_option_and_empty_args_should_print_nothing", NULL, args);
}

void test_echo_with_n_option_should_print_text_without_new_line(void)
{
    char *args[] = {"echo", "-n", "hello", NULL};
    assert_echo_output("test_echo_with_n_option_should_print_text_without_new_line", "hello", args);
}

void test_echo_with_multiple_n_options_should_print_text_without_new_line(void)
{
    char *args[] = {"echo", "-n", "-n", "hello", NULL};
    assert_echo_output("test_echo_with_multiple_n_options_should_print_text_without_new_line", "hello", args);
}

void test_echo_with_multiple_n_chars_should_print_text_without_new_line(void)
{
    char *args[] = {"echo", "-nnnnnn", "hello", NULL};
    assert_echo_output("test_echo_with_multiple_n_chars_should_print_text_without_new_line", "hello", args);
}

void test_echo_with_multiple_words_should_print_text_with_space(void)
{
    char *args[] = {"echo", "hello", "world", NULL};
    assert_echo_output("test_echo_with_multiple_words_should_print_text_with_space", "hello world\n", args);
}

void test_echo_with_unknown_option_should_print_as_text(void)
{
    char *args[] = {"echo", "--", "-n", NULL};
    assert_echo_output("test_echo_with_unknown_option_should_print_as_text", "-- -n\n", args);
}

void test_echo_with_option_between_text_should_print_as_text(void)
{
    char *args[] = {"echo", "-n", "hello", "world", "-n", NULL};
    assert_echo_output("test_echo_with_option_between_text_should_print_as_text", "hello world -n", args);
}

void test_echo_with_n_option_and_unknown_option_should_print_as_text_without_new_line(void)
{
    char *args[] = {"echo", "-n", "-a", NULL};
    assert_echo_output("test_echo_with_n_option_and_unknown_option_should_print_as_text_without_new_line", "-a", args);
}

void test_echo_with_only_spaces_should_print_spaces(void)
{
    char *args[] = {"echo", "    ", NULL};
    assert_echo_output("test_echo_with_only_spaces_should_print_spaces", "    \n", args);
}

void test_echo_with_n_option_uppercase_should_print_as_text(void)
{
    char *args[] = {"echo", "-N", "hello", NULL};
    assert_echo_output("test_echo_with_n_option_uppercase_should_print_as_text", "-N hello\n", args);
}

void test_echo_with_n_option_and_empty_string_should_print_nothing(void)
{
    char *args[] = {"echo", "-n", "", NULL};
    assert_echo_output("test_echo_with_n_option_and_empty_string_should_print_nothing", NULL, args);
}

void test_echo_with_empty_string_should_print_nothing(void)
{
    char *args[] = {"echo", "", NULL};
    assert_echo_output("test_echo_with_empty_string_should_print_nothing", "\n", args);
}

void test_echo_with_multiple_empty_string_should_print_nothing(void)
{
    char *args[] = {"echo", "", "", "", NULL};
    assert_echo_output("test_echo_with_multiple_empty_string_should_print_nothing", "  \n", args);
}