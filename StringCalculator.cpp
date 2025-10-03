#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Returns pointer to number section and fills delimiters_buffer (or NULL if invalid)
static const char* parse_delimiter(const char *numbers, char *delimiters_buffer) {
    if (numbers == NULL || *numbers == '\0') {
        return NULL;
    }

    if (strncmp(numbers, "//", 2) == 0) {
        delimiters_buffer[0] = numbers[2];
        delimiters_buffer[1] = '\0';
        const char *num_section = strchr(numbers, '\n');
        if (num_section == NULL) return NULL;
        return num_section + 1;
    }

    strcpy(delimiters_buffer, ",\n");
    return numbers;
}

// Sum tokens, ignore empty tokens, ignore non-digit tokens for safety
static int sum_numbers(const char *number_section, const char *delimiters) {
    if (number_section == NULL || *number_section == '\0') return 0;

    char *copy = strdup(number_section);
    if (!copy) return 0;

    int sum = 0;
    char *saveptr = NULL;
    char *token = strtok_r(copy, delimiters, &saveptr);

    while (token != NULL) {
        // Defensive check: skip tokens with non-digit chars (except leading '-' maybe)
        int i = 0, valid = 1;
        if (token[0] == '-') i = 1; // allow negative numbers if you want
        for (; token[i] != '\0'; i++) {
            if (!isdigit((unsigned char)token[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            sum += atoi(token);
        }

        token = strtok_r(NULL, delimiters, &saveptr);
    }

    free(copy);
    return sum;
}

int Add(const char *numbers) {
    char delimiters[3] = {0};
    const char *num_section = parse_delimiter(numbers, delimiters);
    return sum_numbers(num_section, delimiters);
}
