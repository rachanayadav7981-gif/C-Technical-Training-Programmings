
#include <stdlib.h>
#include <string.h>
void generate(char** result, char* path,
              int n, int open, int close,
              int* count) {
    if (open == n && close == n) {
        result[*count] = malloc(2 * n + 1);
        strcpy(result[*count], path);
        (*count)++;
        return;
    }
    if (open < n) {
        path[open + close] = '(';
        generate(result, path, n,
                 open + 1, close, count);
    }
    if (close < open) {
        path[open + close] = ')';
        generate(result, path, n,
                 open, close + 1, count);
    }
}
char** generateParenthesis(int n, int* returnSize) {
    int capacity = 1;
    for (int i = 0; i < n; i++)
        capacity *= 4;
    char** result = malloc(capacity * sizeof(char*));
    char* path = calloc(2 * n + 1, sizeof(char));
    *returnSize = 0;
    generate(result, path, n, 0, 0, returnSize);
    free(path);
    return result;
}
