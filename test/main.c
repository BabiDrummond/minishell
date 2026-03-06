/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:31:02 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 21:48:46 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    printf("\n=== RUNNING TESTS ===\n\n");
    printf("\n--- ECHO TESTS ---\n");
    test_echo_with_empty_args_should_print_new_line();
    test_echo_with_n_option_and_empty_args_should_print_nothing();
    test_echo_with_n_option_should_print_text_without_new_line();
    test_echo_with_multiple_n_options_should_print_text_without_new_line();
    test_echo_with_multiple_n_chars_should_print_text_without_new_line();
    test_echo_with_multiple_words_should_print_text_with_space();
    test_echo_with_unknown_option_should_print_as_text();
    test_echo_with_option_between_text_should_print_as_text();
    test_echo_with_n_option_and_unknown_option_should_print_as_text_without_new_line();
    test_echo_with_only_spaces_should_print_spaces();
    test_echo_with_n_option_uppercase_should_print_as_text();
    test_echo_with_n_option_and_empty_string_should_print_nothing();
    test_echo_with_empty_string_should_print_nothing();
    test_echo_with_multiple_empty_string_should_print_nothing();

    t_list *vars = envp_to_lst(envp);
    
    printf("\n--- EXPORT TESTS ---\n");
    test_export_new_variable(&vars);
    test_export_override_existing_variable(&vars);
    test_export_empty_value(&vars);
    test_export_invalid_name_with_special_char(&vars);
    test_export_invalid_name_starting_with_number(&vars);
    test_export_multiple_variables(&vars);
    test_export_variable_with_underscore(&vars);
    test_export_without_value_marks_as_exported(&vars);
    
    printf("\n--- UNSET TESTS ---\n");
    test_unset_existing_variable(&vars);
    test_unset_nonexistent_variable(&vars);
    test_unset_without_arguments(&vars);
    test_unset_invalid_name(&vars);
    test_unset_multiple_variables(&vars);
    test_unset_with_valid_and_invalid_names(&vars);
    
    printf("\n--- ENV TESTS ---\n");
    test_env_shows_exported_variables(&vars);
    test_env_returns_success(&vars);
    test_env_with_empty_value(&vars);
    test_env_does_not_show_unexported_variables(&vars);
    
    printf("\n--- PWD TESTS ---\n");
    test_pwd_returns_success(&vars);
    test_pwd_prints_current_directory(&vars);
    test_pwd_uses_pwd_variable(&vars);
    test_pwd_after_cd(&vars);
    
    printf("\n--- CD TESTS ---\n");
    test_cd_to_valid_directory(&vars);
    test_cd_without_arguments_goes_to_home(&vars);
    test_cd_with_tilde_goes_to_home(&vars);
    test_cd_with_dash_goes_to_oldpwd(&vars);
    test_cd_to_nonexistent_directory_fails(&vars);
    test_cd_without_home_variable_fails(&vars);
    test_cd_updates_oldpwd(&vars);
    test_cd_dash_without_oldpwd_fails(&vars);
    test_cd_with_too_many_arguments_fails(&vars);
    
    printf("\n--- VAR TESTS ---\n");
    test_var_create_valid_variable(&vars);
    test_var_create_invalid_key(&vars);
    test_var_create_with_empty_value(&vars);
    test_var_set_new_variable(&vars);
    test_var_set_override_existing(&vars);
    test_var_set_with_empty_value(&vars);
    test_var_get_existing_variable(&vars);
    test_var_get_nonexistent_variable(&vars);
    test_var_get_value_existing_variable(&vars);
    test_var_get_value_nonexistent_variable(&vars);
    test_var_unset_existing_variable(&vars);
    test_var_unset_nonexistent_variable(&vars);
    test_var_update_changes_value_and_export_status(&vars);
    
    printf("\n--- UTILS TESTS ---\n");
    test_is_valid_key_with_valid_name(&vars);
    test_is_valid_key_with_underscore(&vars);
    test_is_valid_key_starting_with_number(&vars);
    test_is_valid_key_with_special_char(&vars);
    test_is_valid_key_with_dash(&vars);
    test_is_valid_key_empty_string(&vars);
    test_extract_key_with_equal_sign(&vars);
    test_extract_key_without_equal_sign(&vars);
    test_extract_key_with_empty_value(&vars);
    test_extract_key_with_multiple_equals(&vars);
    test_extract_value_with_equal_sign(&vars);
    test_extract_value_without_equal_sign(&vars);
    test_extract_value_with_empty_value(&vars);
    test_extract_value_with_multiple_equals(&vars);

    lst_clear(&vars, var_clear);
    
    printf("\n=== TESTS COMPLETE ===\n");
    return 0;
}
