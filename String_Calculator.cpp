#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Helper function to split a string by delimiters (comma, newline, or custom)
char** split_string(const char *input, char delimiter, int *count) {
    char **result = malloc(10 * sizeof(char*));  // Allocating space for strings
    char *token;
    char *input_copy = strdup(input);
    *count = 0;

    token = strtok(input_copy, &delimiter);
    while (token != NULL) {
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, &delimiter);
    }

    free(input_copy);
    return result;
}

// Add function that calculates the sum
int add(const char *numbers) {
    if (strlen(numbers) == 0) {
        return 0;
    }

    int sum = 0;
    char **tokens;
    int count = 0;

    if (numbers[0] == '/' && numbers[1] == '/') {
        // Custom delimiter handling
        char delimiter = numbers[2];
        tokens = split_string(numbers + 4, delimiter, &count);
    } else {
        // Default delimiter (comma or newline)
        tokens = split_string(numbers, ',', &count);
    }

    // Summing up numbers while checking for negative values
    for (int i = 0; i < count; i++) {
        int num = atoi(tokens[i]);
        if (num < 0) {
            fprintf(stderr, "negatives not allowed: %d\n", num);
            return -1; // Signal error
        }
        if (num <= 1000) {
            sum += num;
        }
        free(tokens[i]); // Free memory for each token
    }

    free(tokens); // Free token array
    return sum;
}
