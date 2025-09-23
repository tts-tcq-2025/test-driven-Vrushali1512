#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(const char *numbers) {
    if (strlen(numbers) == 0) {
        return 0;  // If the string is empty, return 0
    }
    return atoi(numbers);  // Convert the string to an integer and return it
}

void test_single_number() {
    assert(add("1") == 1);  // The result should be 1
}

int main() {
    test_empty_string();
    test_single_number();
    printf("All tests passed!\n");
    return 0;
}
