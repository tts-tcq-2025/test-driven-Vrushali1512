#include <stdio.h>
#include <assert.h>

int add(const char *numbers);

void test_empty_string() {
    assert(add("") == 0);  // We expect the result to be 0
}

int main() {
    test_empty_string();
    printf("Test for empty string passed!\n");
    return 0;
}
