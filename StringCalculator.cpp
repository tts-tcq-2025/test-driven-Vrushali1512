#include "StringCalculator.h"
#include <string.h>
#include <stdlib.h>

int Add(const char *numbers) {
    if (numbers == NULL || *numbers == '\0') {
        return 0;
    }

    const char *delimiters = ",\n";  // Default delimiters
    const char *number_section = numbers;

    // Check for custom delimiter syntax "//<delimiter>\n"
    if (strncmp(numbers, "//", 2) == 0) {
        char custom_delim = numbers[2];
        static char custom_delims[2] = {0};  // one char + null terminator
        custom_delims[0] = custom_delim;
        custom_delims[1] = '\0';
        delimiters = custom_delims;

        // Move pointer to after newline
        number_section = strchr(numbers, '\n');
        if (number_section != NULL) {
            number_section++;  // after '\n'
        } else {
            return 0;  // invalid format
        }
    }

    int sum = 0;
    char *copy = strdup(number_section);
    char *token = strtok(copy, delimiters);

    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, delimiters);
    }

    free(copy);
    return sum;
}
