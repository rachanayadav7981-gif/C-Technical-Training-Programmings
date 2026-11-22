
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool isValid(char* s) {
    int n = strlen(s);
    char* stack = malloc(n * sizeof(char));
    int top = -1;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else {
            if (top == -1) {
                free(stack);
                return false;
            }
            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }
    bool result = (top == -1);
    free(stack);
    return result;
}
