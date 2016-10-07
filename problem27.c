#include <stdio.h>

void reverse(char (*a)[], int k) {
    int i;
    char *tmp;

    for (i = 0; i < (k - 1) / 2; i++) {
        tmp = *(*a)[i];
        *(*a)[i] = *(*a)[k - i - 1];
        *(*a)[k - i -1] = tmp;
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
