#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int stringedit(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int count[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                count[i][j] = j;
            } else if (j == 0) {
                count[i][j] = i;
            } else if (str1[i-1] == str2[j-1]) {
                count[i][j] = count[i-1][j-1];
            } else {
                count[i][j] = 1 + min(count[i-1][j], count[i][j-1], count[i-1][j-1]);
            }
        }
    }
    return count[m][n];
}

int main() {
    char str1[100], str2[100];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    int count = stringedit(str1, str2);

    printf("The minimum number of edits required to convert %s to %s is %d.\n", str1, str2, count);
    return 0;
}