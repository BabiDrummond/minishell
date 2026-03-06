/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:18:17 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 21:53:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "minishell.h"
# include "../libft/include/libft.h"

/* Echo Tests */
void test_echo_with_empty_args_should_print_new_line(void);
void test_echo_with_n_option_and_empty_args_should_print_nothing(void);
void test_echo_with_n_option_should_print_text_without_new_line(void);
void test_echo_with_multiple_n_options_should_print_text_without_new_line(void);
void test_echo_with_multiple_n_chars_should_print_text_without_new_line(void);
void test_echo_with_multiple_words_should_print_text_with_space(void);
void test_echo_with_unknown_option_should_print_as_text(void);
void test_echo_with_option_between_text_should_print_as_text(void);
void test_echo_with_n_option_and_unknown_option_should_print_as_text_without_new_line(void);
void test_echo_with_only_spaces_should_print_spaces(void);
void test_echo_with_n_option_uppercase_should_print_as_text(void);
void test_echo_with_n_option_and_empty_string_should_print_nothing(void);
void test_echo_with_empty_string_should_print_nothing(void);
void test_echo_with_multiple_empty_string_should_print_nothing(void);

/* Export Tests */
void test_export_new_variable(t_list **vars);
void test_export_override_existing_variable(t_list **vars);
void test_export_empty_value(t_list **vars);
void test_export_invalid_name_with_special_char(t_list **vars);
void test_export_invalid_name_starting_with_number(t_list **vars);
void test_export_multiple_variables(t_list **vars);
void test_export_variable_with_underscore(t_list **vars);

#endif