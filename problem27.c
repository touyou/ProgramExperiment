#include <stdio.h>

void reverse(char (*a)[10], int k) {
    int i;

    for (i = 0; i < (k - 1) / 2; i++) {
        for (int j=0; j<10; j++) {
            char tmp3 = a[i][j];
            a[i][j] = a[k - i - 1][j];
            a[k - i - 1][j] = tmp3;
        }
    }
}

int main(int argc, char *argv[]) {
    char a[5][10] = {"", "", "", "", ""};
    int i;

    for (i = 0; i < 5; i++)
        scanf("%9s", a[i]);

    reverse(a, 5);

    for (i = 0; i < 5; i++)
        printf("%s\n", a[i]);

    return 0;
}
