#include <stdio.h>
#include <assert.h>
#include "StringCalculator.h"

void test_empty_string_returns_0() {
    assert(Add("") == 0);
    printf("test_empty_string_returns_0 passed.\n");
}

int main() {
    test_empty_string_returns_0();
    printf("All tests passed.\n");
    return 0;
}
