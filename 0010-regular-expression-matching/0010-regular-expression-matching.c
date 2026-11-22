
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p) {

    int m = strlen(s);
    int n = strlen(p);

    int* dp = calloc((m + 1) * (n + 1), sizeof(int));

    #define DP(i,j) dp[(i) * (n + 1) + (j)]

    DP(0, 0) = 1;

    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*')
            DP(0, j) = DP(0, j - 2);
    }

    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (p[j - 1] == '.' ||
                p[j - 1] == s[i - 1]) {

                DP(i, j) = DP(i - 1, j - 1);
            }

            else if (p[j - 1] == '*') {

                DP(i, j) = DP(i, j - 2);

                if (p[j - 2] == '.' ||
                    p[j - 2] == s[i - 1]) {

                    DP(i, j) = DP(i, j) || DP(i - 1, j);
                }
            }
        }
    }

    bool result = DP(m, n);

    free(dp);

    return result;

    #undef DP
}
