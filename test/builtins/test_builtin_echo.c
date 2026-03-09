/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:20:37 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/09 16:45:09 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void assert_echo_output(char *test_name, char *expected, char **argv)
{
    int saved_stdout = dup(STDOUT_FILENO);
    FILE *temp = tmpfile();
    int temp_fd = fileno(temp);
    
    fflush(stdout);
    dup2(temp_fd, STDOUT_FILENO);
    
    builtin_echo(argv);
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
    char *argv[] = {"echo", NULL};
    assert_echo_output("test_echo_with_empty_args_should_print_new_line", "\n", argv);
}

void test_echo_with_n_option_and_empty_args_should_print_nothing(void)
{
    char *argv[] = {"echo", "-n", NULL};
    assert_echo_output("test_echo_with_n_option_and_empty_args_should_print_nothing", NULL, argv);
}

void test_echo_with_n_option_should_print_text_without_new_line(void)
{
    char *argv[] = {"echo", "-n", "hello", NULL};
    assert_echo_output("test_echo_with_n_option_should_print_text_without_new_line", "hello", argv);
}

void test_echo_with_multiple_n_options_should_print_text_without_new_line(void)
{
    char *argv[] = {"echo", "-n", "-n", "hello", NULL};
    assert_echo_output("test_echo_with_multiple_n_options_should_print_text_without_new_line", "hello", argv);
}

void test_echo_with_multiple_n_chars_should_print_text_without_new_line(void)
{
    char *argv[] = {"echo", "-nnnnnn", "hello", NULL};
    assert_echo_output("test_echo_with_multiple_n_chars_should_print_text_without_new_line", "hello", argv);
}

void test_echo_with_multiple_words_should_print_text_with_space(void)
{
    char *argv[] = {"echo", "hello", "world", NULL};
    assert_echo_output("test_echo_with_multiple_words_should_print_text_with_space", "hello world\n", argv);
}

void test_echo_with_unknown_option_should_print_as_text(void)
{
    char *argv[] = {"echo", "--", "-n", NULL};
    assert_echo_output("test_echo_with_unknown_option_should_print_as_text", "-- -n\n", argv);
}

void test_echo_with_option_between_text_should_print_as_text(void)
{
    char *argv[] = {"echo", "-n", "hello", "world", "-n", NULL};
    assert_echo_output("test_echo_with_option_between_text_should_print_as_text", "hello world -n", argv);
}

void test_echo_with_n_option_and_unknown_option_should_print_as_text_without_new_line(void)
{
    char *argv[] = {"echo", "-n", "-a", NULL};
    assert_echo_output("test_echo_with_n_option_and_unknown_option_should_print_as_text_without_new_line", "-a", argv);
}

void test_echo_with_only_spaces_should_print_spaces(void)
{
    char *argv[] = {"echo", "    ", NULL};
    assert_echo_output("test_echo_with_only_spaces_should_print_spaces", "    \n", argv);
}

void test_echo_with_n_option_uppercase_should_print_as_text(void)
{
    char *argv[] = {"echo", "-N", "hello", NULL};
    assert_echo_output("test_echo_with_n_option_uppercase_should_print_as_text", "-N hello\n", argv);
}

void test_echo_with_n_option_and_empty_string_should_print_nothing(void)
{
    char *argv[] = {"echo", "-n", "", NULL};
    assert_echo_output("test_echo_with_n_option_and_empty_string_should_print_nothing", NULL, argv);
}

void test_echo_with_empty_string_should_print_nothing(void)
{
    char *argv[] = {"echo", "", NULL};
    assert_echo_output("test_echo_with_empty_string_should_print_nothing", "\n", argv);
}

void test_echo_with_multiple_empty_string_should_print_nothing(void)
{
    char *argv[] = {"echo", "", "", "", NULL};
    assert_echo_output("test_echo_with_multiple_empty_string_should_print_nothing", "  \n", argv);
}