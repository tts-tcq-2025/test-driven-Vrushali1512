#include "StringCalculator.h"
#include <string.h>
#include <stdlib.h>

int Add(const char *numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }
        
    int sum = 0;
    const char *delimiter = ",";  // default delimiter

    char *copy = strdup(numbers);  // duplicate string for safe tokenizing
    char *token = strtok(copy, delimiter);
    
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, delimiter);
    }

    free(copy);
    return sum;
}
