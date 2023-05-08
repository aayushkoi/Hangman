#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_ak_destroy_sets_object_to_null(char* buffer, int length);
Status test_ak_init_c_string_sets_the_correct_string(char* buffer, int length);
Status test_ak_init_c_string_sets_correct_size(char* buffer, int length);
Status test_ak_init_c_string_sets_correct_capacity(char* buffer, int length);
Status test_ak_get_size_returns_correct_number(char* buffer, int length);
Status test_ak_get_capacity_returns_correct_number(char* buffer, int length);
Status test_ak_compare_same_string_returns_0(char* buffer, int length);
Status test_ak_compare_different_string_returns_not0(char* buffer, int length);
Status test_ak_extraction_sets_correct_string(char* buffer, int length);
Status test_ak_extraction_sets_correct_size(char* buffer, int length);
Status test_ak_insertion_inserts_correct_string(char* buffer, int length);
Status test_ak_push_back_sets_correct_short_string(char* buffer, int length);
Status test_ak_push_back_sets_correct_long_string(char* buffer, int length);
Status test_ak_push_back_sets_correct_size_short(char* buffer, int length);
Status test_ak_push_back_sets_correct_size_long(char* buffer, int length);
Status test_ak_push_back_sets_correct_capacity_long(char* buffer, int length);
Status test_ak_pop_back_sets_correct_size(char* buffer, int length);
Status test_ak_concat_sets_right_string(char* buffer, int length);
Status test_ak_concat_sets_right_size(char* buffer, int length);
Status test_ak_at_returns_right_adress(char* buffer, int length);
Status test_ak_c_str_returns_right_adress(char* buffer, int length);
Status test_ak_empty_returns_true(char* buffer, int length);
Status test_ak_empty_returns_false(char* buffer, int length);

#endif
