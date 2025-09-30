#include "StringCalculator.h"
#include <string.h>
#include <stdlib.h>

int Add(const char *numbers) {
    if (numbers == NULL || *numbers == '\0') {
        return 0;
    }

    int sum = 0;
    char *copy = strdup(numbers);
    char *token = strtok_r(copy, ",\n");

    while (token) {
        sum += atoi(token);
        token = strtok_r(NULL, ",\n");
    }

    free(copy);
    return sum;
}
