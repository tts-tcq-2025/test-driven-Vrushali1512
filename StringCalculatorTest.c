#include <stdio.h>
#include <assert.h>
#include "StringCalculator.h"

// Test for empty string
void test_empty_string() {
    assert(Add("") == 0);
}

// Test for a single number
void test_single_number() {
    assert(Add("1") == 1);
}

// Test for two numbers
void test_two_numbers() {
    assert(Add("1,2") == 3);
}

// Test for numbers with newline
void test_newline_delimited_numbers() {
    assert(Add("1\n2,3") == 6);
}

// Test for custom delimiter
void test_custom_delimiter() {
    assert(Add("//;\n1;2") == 3);
}

// Test for numbers larger than 1000 (should be ignored)
void test_ignore_large_numbers() {
    assert(Add("1001,2") == 2);
}

// Test for negative numbers (should throw an exception)
void test_negative_numbers() {
    int result = Add("-1,2");
    assert(result == -1); // -1 indicates negative number error
}

// Run all tests
void run_tests() {
    test_empty_string();
    test_single_number();
    test_two_numbers();
    test_newline_delimited_numbers();
    test_custom_delimiter();
    test_ignore_large_numbers();
    test_negative_numbers();
    printf("All tests passed.\n");
}

int main() {
    run_tests();
    return 0;
}
