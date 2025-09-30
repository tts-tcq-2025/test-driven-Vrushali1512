#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>

int Add(const char *numbers) {
    if (numbers == NULL || *numbers == '\0') {
        return 0;
    }

    const char *delimiters = ",\n";  // Default delimiters
    const char *number_section = numbers;

    if (strncmp(numbers, "//", 2) == 0) {
        char custom_delim = numbers[2];
        static char custom_delims[2] = {0};
        custom_delims[0] = custom_delim;
        custom_delims[1] = '\0';
        delimiters = custom_delims;

        number_section = strchr(numbers, '\n');
        if (number_section == NULL) {
            return 0;
        }
        number_section++;
    }

    int sum = 0;
    char *copy = strdup(number_section);
    if (copy == NULL) {
        return 0;
    }

    char *saveptr = NULL;
    char *temp_token = strtok_r(copy, delimiters, &saveptr);
    const char *token = NULL;

    while (temp_token != NULL) {
        token = temp_token;  // assign to const pointer (read-only)
        sum += atoi(token);
        temp_token = strtok_r(NULL, delimiters, &saveptr);
    }

    free(copy);
    return sum;
}
