#include <stdio.h>
#include <assert.h>
#include "StringCalculator.h"

void test_empty_string_returns_0() {
    assert(Add("") == 0);
    printf("test_empty_string_returns_0 passed.\n");
}

void test_single_number_returns_value() {
    assert(Add("1") == 1);
    printf("test_single_number_returns_value passed.\n");
}

void test_two_numbers_comma_separated() {
    assert(Add("1,2") == 3);
    printf("test_two_numbers_comma_separated passed.\n");
}

void test_multiple_numbers_comma_separated() {
    assert(Add("1,2,3,4") == 10);
    printf("test_multiple_numbers_comma_separated passed.\n");
}

void test_newline_and_comma_delimiters() {
    assert(Add("1\n2,3") == 6);
    printf("test_newline_and_comma_delimiters passed.\n");
}

int main() {
    test_empty_string_returns_0();
    test_single_number_returns_value();
    test_two_numbers_comma_separated();
    test_multiple_numbers_comma_separated();
    test_newline_and_comma_delimiters();
    printf("All tests passed.\n");
    return 0;
}
