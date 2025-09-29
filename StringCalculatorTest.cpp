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

int main() {
    test_empty_string_returns_0();
    test_single_number_returns_value();
    printf("All tests passed.\n");
    return 0;
}
