
#include <stdlib.h>
#include <string.h>
char* mapping[] = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};
void backtrack(char* digits, int index,
               char* path, char** result,
               int* count) {
    if (digits[index] == '\0') {
        result[*count] = malloc(strlen(path) + 1);
        strcpy(result[*count], path);
        (*count)++;
        return;
    }
    int digit = digits[index] - '0';
    for (int i = 0; mapping[digit][i] != '\0'; i++) {
        path[index] = mapping[digit][i];
        path[index + 1] = '\0';
        backtrack(digits, index + 1,
                  path, result, count);
    }
}
char** letterCombinations(char* digits,
                          int* returnSize) {
    *returnSize = 0;

    if (digits[0] == '\0')
        return NULL;
    int n = strlen(digits);
    int capacity = 1;
    for (int i = 0; i < n; i++) {
        capacity *= 4;
    }
    char** result = malloc(capacity * sizeof(char*));
    char* path = calloc(n + 1, sizeof(char));
    backtrack(digits, 0, path, result, returnSize);
    free(path);
    return result;
}
