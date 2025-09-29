#include "StringCalculator.h"
#include <string.h>
#include <stdlib.h>

int Add(const char *numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }
    // For now, assume single number string, convert to int
    return atoi(numbers);
}
