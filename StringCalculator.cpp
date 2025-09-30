#include "StringCalculator.h"
#include <string.h>
#include <stdlib.h>

int Add(const char *numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }
    
    int sum = 0;
    char *copy = strdup(numbers);
    char *token = strtok(copy, ",");

    while (token) {
        sum += atoi(token);
        token = strtok(NULL, ",");
    }

    free(copy);
    return sum;
}
