#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
	Status(*tests[])(char*, int) =
	{
		test_init_default_returns_nonNULL,
		test_get_size_on_init_default_returns_0,
		test_ak_destroy_sets_object_to_null,
		test_ak_init_c_string_sets_the_correct_string,
		test_ak_init_c_string_sets_correct_size,
		test_ak_init_c_string_sets_correct_capacity,
		test_ak_get_size_returns_correct_number,
		test_ak_get_capacity_returns_correct_number,
		test_ak_compare_same_string_returns_0,
		test_ak_compare_different_string_returns_not0,
		test_ak_extraction_sets_correct_string,
		test_ak_extraction_sets_correct_size,
		test_ak_insertion_inserts_correct_string,
		test_ak_push_back_sets_correct_short_string,
		test_ak_push_back_sets_correct_long_string,
		test_ak_push_back_sets_correct_size_short,
		test_ak_push_back_sets_correct_size_long,
		test_ak_push_back_sets_correct_capacity_long,
		test_ak_pop_back_sets_correct_size,
		test_ak_concat_sets_right_string,
		test_ak_concat_sets_right_size,
		test_ak_at_returns_right_adress,
		test_ak_c_str_returns_right_adress,
		test_ak_empty_returns_true,
		test_ak_empty_returns_false

	};
	int number_of_functions = sizeof(tests) / sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;
	for (i = 0; i < number_of_functions; i++)
	{
		if (tests[i](buffer, 500) == Failure)
		{
			printf("FAILED: Test %d failed miserably\n", i);
			printf("\t%s\n", buffer);
			failure_count++;
		}
		else
		{
			success_count++;
		}
	}
	printf("Total number of tests: %d\n", number_of_functions);
	printf("%d/%d Pass, %d/%d Failure\n", success_count,
			number_of_functions, failure_count, number_of_functions);
	return 0;
}

