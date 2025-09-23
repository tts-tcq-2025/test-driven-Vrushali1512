#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "string_calculator.c"

void test_empty_string() {
    assert(add("") == 0);
}

void test_single_number() {
    assert(add("1") == 1);
}

void test_two_numbers() {
    assert(add("1,2") == 3);
}

void test_multiple_numbers_with_newline_and_comma() {
    assert(add("1\n2,3") == 6);
}

void test_negative_numbers() {
    assert(add("1,-2,3") == -1);  // This should print an error message
}

void test_ignore_numbers_greater_than_1000() {
    assert(add("2,1001") == 2);
}

void test_custom_delimiter() {
    assert(add("//;\n1;2") == 3);
}

void test_custom_delimiter_of_variable_length() {
    assert(add("//***\n12***3") == 15);
}

int main() {
    test_empty_string();
    test_single_number();
    test_two_numbers();
    test_multiple_numbers_with_newline_and_comma();
    test_negative_numbers();
    test_ignore_numbers_greater_than_1000();
    test_custom_delimiter();
    test_custom_delimiter_of_variable_length();

    printf("All tests passed!\n");
    return 0;
}
