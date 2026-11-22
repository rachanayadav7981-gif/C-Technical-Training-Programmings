
#include <stdlib.h>
#include <string.h>
char* convert(char* s, int numRows) {
    int n = strlen(s);
    char* result = malloc(n + 1);
    if (numRows == 1 || numRows >= n) {
        strcpy(result, s);
        return result;
    }
    int index = 0;
    for (int row = 0; row < numRows; row++) {
        int step1 = 2 * (numRows - row - 1);
        int step2 = 2 * row;
        int pos = row;
        int toggle = 0;
        while (pos < n) {
            result[index++] = s[pos];
            int step;
            if (row == 0)
                step = step1;
            else if (row == numRows - 1)
                step = step2;
            else
                step = toggle ? step2 : step1;
            pos += step;
            if (row != 0 && row != numRows - 1)
                toggle = !toggle;
        }
    }
    result[index] = '\0';
    return result;
}
