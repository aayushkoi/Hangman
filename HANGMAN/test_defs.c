
#include "unit_test.h"
#include "my_string.h"
#include <string.h>



Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	if (hString == NULL)
	{
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
				"my_string_init_default returns NULL", length);
		return Failure;
	}
	else
	{
		my_string_destroy((ITEM*)&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return Success;
	}
}



Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	if (my_string_get_size(hString) != 0)
	{
		status = Failure;
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				"Did not receive 0 from get_size after init_default\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				, length);
	}
	my_string_destroy(&hString);
	return status;
}



Status test_ak_destroy_sets_object_to_null(char* buffer, int length)
{



	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	my_string_destroy((ITEM*)&hString);
	if (hString != NULL)
	{
		status = Failure;
		printf("Expected NULL but got the adress %p\n", hString);
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				"Did not receive NULL from my_string_destroy after init_default\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_destroy_sets_object_to_null\n"
				, length);
	}



	return status;
}



Status test_ak_init_c_string_sets_the_correct_string(char* buffer, int length)
{



	MY_STRING hString = NULL;
	Status status;
	char c[] = "Testing 1, 2, 3";
	hString = my_string_init_c_string(c);

	for (int i = 0; i < my_string_get_size(hString); i++) {
		if (*my_string_at(hString, i) != c[i])
		{
			status = Failure;
			printf("expected the char %c but got char %c\n", c[i], *my_string_at(hString, i));
			strncpy(buffer, "test_ak_init_c_string_sets_the_correct_string\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_init_c_string_sets_the_correct_string\n"
					, length);
		}
	}
	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_init_c_string_sets_correct_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "Testing 1, 2, 3";
	hString = my_string_init_c_string(c);



	if (my_string_get_size(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the number %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_init_c_string_sets_correct_size\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_init_c_string_sets_correct_size\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_init_c_string_sets_correct_capacity(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "Testing 1, 2, 3";
	hString = my_string_init_c_string(c);



	if (my_string_get_capacity(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the number %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_init_c_string_sets_correct_capacity\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_init_c_string_sets_correct_capacity\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_get_capacity_returns_correct_number(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "Testing 1, 2, 3";
	hString = my_string_init_c_string(c);



	if (my_string_get_capacity(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the number %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_get_capacity_returns_correct_number\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_get_capacity_returns_correct_number\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_get_size_returns_correct_number(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "Testing 1, 2, 3";
	hString = my_string_init_c_string(c);



	if (my_string_get_size(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the number %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_get_size_returns_correct_number\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_get_size_returns_correct_number\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_compare_same_string_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "Testing 1, 2, 3";
	hString = my_string_init_c_string(c);



	if (my_string_compare(hString, hString) != 0)
	{
		status = Failure;
		printf("expected the number %d but got %d\n", 0, my_string_compare(hString, hString));
		strncpy(buffer, "test_ak_compare_same_string_returns_0\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_compare_same_string_returns_0\n", length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_compare_different_string_returns_not0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString0 = NULL;
	Status status;
	hString = my_string_init_c_string("idaho");
	hString0 = my_string_init_c_string("iowa");



	if (my_string_compare(hString, hString0) == 0)
	{
		status = Failure;
		printf("expected the number %d but got %d\n", my_string_compare(hString, hString0), 0);
		strncpy(buffer, "test_ak_compare_different_string_returns_not0\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_compare_different_string_returns_not0\n", length);
	}



	my_string_destroy((ITEM*)&hString);
	my_string_destroy((ITEM*)&hString0);
	return status;
}






Status test_ak_extraction_sets_correct_string(char* buffer, int length)
{



	MY_STRING hString = NULL;
	FILE* fp = fopen("simple.txt", "r");
	Status status;
	char c[] = "The";
	hString = my_string_init_default();



	my_string_extraction(hString, fp);



	for (int i = 0; i < my_string_get_size(hString); i++) {
		if (*my_string_at(hString, i) != c[i])
		{
			status = Failure;
			printf("expected the char %c but got char %c\n", c[i], *my_string_at(hString, i));
			strncpy(buffer, "test_ak_extraction_sets_correct_string\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_extraction_sets_correct_string\n"
					, length);
		}
	}
	fclose(fp);
	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_extraction_sets_correct_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	FILE* fp = fopen("simple.txt", "r");
	Status status;
	char c[] = "The";
	hString = my_string_init_default();



	my_string_extraction(hString, fp);



	if (my_string_get_size(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the number %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_extraction_sets_correct_size\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_extraction_sets_correct_size\n", length);
	}
	fclose(fp);
	my_string_destroy((ITEM*)&hString);
	return status;
}






Status test_ak_insertion_inserts_correct_string(char* buffer, int length)
{
	MY_STRING hString0 = NULL;
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("test");
	hString0 = my_string_init_default();



	FILE* fp = fopen("test.txt", "w");
	my_string_insertion(hString, fp);
	fclose(fp);



	fp = fopen("test.txt", "r");
	my_string_extraction(hString0, fp);
	fclose(fp);



	for (int i = 0; i < my_string_get_size(hString0); i++) {
		if (*my_string_at(hString, i) != *my_string_at(hString0, i))
		{
			status = Failure;
			printf("expected the char %c but got char %c\n", *my_string_at(hString, i), *my_string_at(hString0, i));
			strncpy(buffer, "test_ak_insertion_inserts_correct_string\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_insertion_inserts_correct_string\n"
					, length);
		}
	}
	my_string_destroy((ITEM*)&hString);
	my_string_destroy((ITEM*)&hString0);
	return status;
}



Status test_ak_push_back_sets_correct_short_string(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	char c[] = "Test";
	hString = my_string_init_default();



	for (int i = 0; i < strlen(c); i++) {
		my_string_push_back(hString, c[i]);
	}



	for (int i = 0; i < my_string_get_size(hString); i++) {
		if (*my_string_at(hString, i) != c[i])
		{
			status = Failure;
			printf("expected the char %c but got char %c\n", c[i], *my_string_at(hString, i));
			strncpy(buffer, "test_ak_push_back_sets_correct_short_string\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_push_back_sets_correct_short_string\n"
					, length);
		}
	}
	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_push_back_sets_correct_long_string(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	char c[] = "This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3.";
	hString = my_string_init_default();



	for (int i = 0; i < strlen(c); i++) {
		my_string_push_back(hString, c[i]);
	}



	for (int i = 0; i < my_string_get_size(hString); i++) {
		if (*my_string_at(hString, i) != c[i])
		{
			status = Failure;
			printf("expected the char %c but got char %c\n", c[i], *my_string_at(hString, i));
			strncpy(buffer, "test_ak_push_back_sets_correct_long_string\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_push_back_sets_correct_long_string\n"
					, length);
		}
	}
	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_push_back_sets_correct_size_short(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	char c[] = "test";
	hString = my_string_init_default();



	for (int i = 0; i < strlen(c); i++) {
		my_string_push_back(hString, c[i]);
	}



	if (my_string_get_size(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the num %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_push_back_sets_correct_size_short\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_push_back_sets_correct_size_short\n"
				, length);
	}

	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_push_back_sets_correct_size_long(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	char c[] = "This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3.";
	hString = my_string_init_default();



	for (int i = 0; i < strlen(c); i++) {
		my_string_push_back(hString, c[i]);
	}



	if (my_string_get_size(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the num %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_push_back_sets_correct_size_short\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_push_back_sets_correct_size_short\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_push_back_sets_correct_capacity_long(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	int capacity;
	char c[] = "This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3. This is a test 1, 2, 3.";
	hString = my_string_init_default();
	capacity = my_string_get_capacity(hString);



	for (int i = 0; i < (capacity + 2); i++) {
		my_string_push_back(hString, c[i]);
	}



	if (my_string_get_capacity(hString) != (capacity * 2))
	{
		status = Failure;
		printf("expected the num %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_push_back_sets_correct_capacity_long\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_push_back_sets_correct_capacity_long\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_pop_back_sets_correct_size(char* buffer, int length) {
	MY_STRING hString = NULL;
	Status status;
	char c[] = "This is a test.";
	hString = my_string_init_c_string(c);
	int size = my_string_get_capacity(hString);



	for (int i = 0; i < 5; i++) {
		my_string_pop_back(hString);
	}



	if (my_string_get_size(hString) != (size - 5))
	{
		status = Failure;
		printf("expected the num %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_pop_back_sets_correct_size\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_pop_back_sets_correct_size\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_concat_sets_right_string(char* buffer, int length)
{
	MY_STRING hString0 = NULL;
	MY_STRING hString = NULL;
	Status status;
	char c[] = "This is a test";
	hString = my_string_init_c_string("This is ");
	hString0 = my_string_init_c_string("a test");



	my_string_concat(hString, hString0);



	for (int i = 0; i < strlen(c); i++) {
		if (*my_string_at(hString, i) != c[i])
		{
			status = Failure;
			printf("expected the char %c but got char %c\n", *my_string_at(hString, i), *my_string_at(hString0, i));
			strncpy(buffer, "test_ak_concat_sets_right_string\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_concat_sets_right_string\n"
					, length);
		}
	}
	my_string_destroy((ITEM*)&hString);
	my_string_destroy((ITEM*)&hString0);
	return status;
}



Status test_ak_concat_sets_right_size(char* buffer, int length)
{
	MY_STRING hString0 = NULL;
	MY_STRING hString = NULL;
	Status status;
	char c[] = "This is a test";
	hString = my_string_init_c_string("This is ");
	hString0 = my_string_init_c_string("a test");



	my_string_concat(hString, hString0);






	if (my_string_get_size(hString) != strlen(c))
	{
		status = Failure;
		printf("expected the num %d but got %d\n", strlen(c), my_string_get_size(hString));
		strncpy(buffer, "test_ak_concat_sets_right_size\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_concat_sets_right_size\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	my_string_destroy((ITEM*)&hString0);
	return status;
}



Status test_ak_at_returns_right_adress(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "This is a test";
	hString = my_string_init_c_string(c);



	for (int i = 0; i < my_string_get_size(hString); i++) {
		if (*my_string_at(hString, i) != c[i])
		{
			status = Failure;
			printf("expected the char %c but got %c\n", c[i], *my_string_at(hString, i));
			strncpy(buffer, "test_ak_at_returns_right_adress\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_at_returns_right_adress\n"
					, length);
		}
	}
	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_c_str_returns_right_adress(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "This is a test";
	hString = my_string_init_c_string(c);



	for (int i = 0; i < my_string_get_size(hString); i++) {
		if (my_string_c_str(hString)[i] != c[i])
		{
			status = Failure;
			printf("expected the char %c but got %c\n", c[i], *my_string_at(hString, i));
			strncpy(buffer, "test_ak_c_str_returns_right_adress\n", length);
		}
		else
		{
			status = Success;
			strncpy(buffer, "test_ak_c_str_returns_right_adress\n"
					, length);
		}
	}
	my_string_destroy((ITEM*)&hString);
	return status;
}



Status test_ak_empty_returns_false(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("This is a test");



	if (my_string_empty(hString) != FALSE)
	{
		status = Failure;
		printf("expected the bool %d but got %d\n", my_string_empty(hString), TRUE);
		strncpy(buffer, "test_ak_empty_returns_false\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_empty_returns_false\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}






Status test_ak_empty_returns_true(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();



	if (my_string_empty(hString) != TRUE)
	{
		status = Failure;
		printf("expected the bool %d but got %d\n", my_string_empty(hString), FALSE);
		strncpy(buffer, "test_ak_empty_returns_true\n", length);
	}
	else
	{
		status = Success;
		strncpy(buffer, "test_ak_empty_returns_true\n"
				, length);
	}



	my_string_destroy((ITEM*)&hString);
	return status;
}




