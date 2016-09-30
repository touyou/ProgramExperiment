#include <stdio.h>

int main(int argc, char *argv[]) {
    int a[5] = {0, 0, 0, 0, 0};
    int b[5] = {0, 0, 0, 0, 0};
    int i;

    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 5; i++)
        b[i] = a[4 - i];
    for (i = 0; i < 5; i++)
        printf("%d\n", b[i]);

    return 0;
}
