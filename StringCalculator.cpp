#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>

int Add(const char *numbers) {
    if (numbers == NULL || *numbers == '\0') {
        return 0;  // Early return for empty input
    }

    const char *delimiters = ",\n";  // Default delimiters
    const char *number_section = numbers;

    if (strncmp(numbers, "//", 2) == 0) {
        // Custom delimiter
        char custom_delim = numbers[2];
        static char custom_delims[2] = { custom_delim, '\0' };
        delimiters = custom_delims;

        number_section = strchr(numbers, '\n');
        if (number_section == NULL) {
            return 0;  // Invalid format
        }
        number_section++;  // Move past '\n'
    }

    int sum = 0;
    char *copy = strdup(number_section);
    if (copy == NULL) {
        return 0;  // Memory allocation failure guard
    }

    char *saveptr = NULL;
    char *token = strtok_r(copy, delimiters, &saveptr);
    while (token != NULL) {
        sum += atoi(token);
        token = strtok_r(NULL, delimiters, &saveptr);
    }

    free(copy);
    return sum;
}
