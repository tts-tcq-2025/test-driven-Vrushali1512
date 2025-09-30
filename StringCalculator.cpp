#include "StringCalculator.h"
#include <stdlib.h>

int Add(const char *numbers) {
    if (numbers == NULL || *numbers == '\0') {
        return 0;
    }

    int sum = 0;
    const char *start = numbers;
    const char *p = numbers;

    while (*p != '\0') {
        if (*p == ',' || *p == '\n') {
            // Calculate length of token
            int len = p - start;
            if (len > 0) {
                // Copy substring to temp buffer
                char *token = (char *)malloc(len + 1);
                for (int i = 0; i < len; i++) {
                    token[i] = start[i];
                }
                token[len] = '\0';

                sum += atoi(token);
                free(token);
            }
            start = p + 1;
        }
        p++;
    }

    // Last token after loop ends
    if (*start != '\0') {
        sum += atoi(start);
    }

    return sum;
}
