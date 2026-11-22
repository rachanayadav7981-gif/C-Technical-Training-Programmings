
#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";
    int i = 0;
    while (strs[0][i] != '\0') {
        char ch = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != ch) {
                char* result = malloc(i + 1);
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
        i++;
    }
    char* result = malloc(i + 1);
    strcpy(result, strs[0]);
    return result;
}
