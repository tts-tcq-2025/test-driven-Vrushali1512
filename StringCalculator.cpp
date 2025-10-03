#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>

static const char* parse_delimiter(const char *numbers, char *delimiters_buffer) {
    if (strncmp(numbers, "//", 2) == 0) {
        delimiters_buffer[0] = numbers[2];
        delimiters_buffer[1] = '\0';
        const char *number_section = strchr(numbers, '\n');
        if (number_section == NULL) {
            return NULL;
        }
        return number_section + 1;  // Return pointer after newline
    }
    strcpy(delimiters_buffer, ",\n");
    return numbers;
}

static int sum_numbers(const char *number_section, const char *delimiters) {
    int sum = 0;
    char *copy = strdup(number_section);
    if (copy == NULL) {
        return 0;
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

int Add(const char *numbers) {
    if (numbers == NULL || *numbers == '\0') {
        return 0;
    }

    char delimiters[3] = {0};  // Enough to hold one custom delimiter + null terminator or default ",\n"
    const char *number_section = parse_delimiter(numbers, delimiters);
    if (number_section == NULL) {
        return 0;
    }

    return sum_numbers(number_section, delimiters);
}
