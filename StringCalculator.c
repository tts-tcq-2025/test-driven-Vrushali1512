#include "StringCalculator.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

// Helper function to split string by a delimiter
int split_and_sum(const char *str, const char *delimiter) {
    int sum = 0;
    char *input_copy = strdup(str);
    char *token = strtok(input_copy, delimiter);
    
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0) {
            free(input_copy);
            return -1;  // Indicates negative number found
        }
        if (num <= 1000) {
            sum += num;
        }
        token = strtok(NULL, delimiter);
    }

    free(input_copy);
    return sum;
}

int Add(const char *input) {
    if (input == NULL || strlen(input) == 0) {
        return 0;
    }

    // Check for custom delimiter at the start
    if (input[0] == '/' && input[1] == '/') {
        const char *delimiter_start = strchr(input, '\n');
        if (!delimiter_start) return 0; // No delimiter line found

        char delimiter[MAX_INPUT_SIZE];
        int delimiter_length = delimiter_start - input - 2;
        strncpy(delimiter, input + 2, delimiter_length);
        delimiter[delimiter_length] = '\0';
        
        return split_and_sum(delimiter_start + 1, delimiter);
    }

    // Default delimiter is ',' and '\n'
    return split_and_sum(input, ",\n");
}
