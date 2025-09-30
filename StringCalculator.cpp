#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>

int Add(const char *numbers) {
    if (numbers == NULL || *numbers == '\0') {
        return 0;
    }

    const char *delimiters = ",\n";  // Default delimiters
    const char *number_section = numbers;

    // Check for custom delimiter format "//<delimiter>\n"
    if (strncmp(numbers, "//", 2) == 0) {
        char custom_delim = numbers[2];
        static char custom_delims[2] = {0};
        custom_delims[0] = custom_delim;
        custom_delims[1] = '\0';
        delimiters = custom_delims;

        number_section = strchr(numbers, '\n');
        if (number_section != NULL) {
            number_section++;  // Move past '\n'
        } else {
            return 0;  // Invalid format
        }
    }

    int sum = 0;
    char *copy = strdup(number_section);
    char *saveptr = NULL;
    char *token = strtok_r(copy, delimiters, &saveptr);

    while (token != NULL) {
        sum += atoi(token);
        token = strtok_r(NULL, delimiters, &saveptr);
    }

    free(copy);
    return sum;
}
