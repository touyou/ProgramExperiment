#include <stdio.h>

void reverse(int *a, int size) {
    int b[size];
    for (int i=0; i<size; i++)
        b[i] = a[size-1-i];
    for (int i=0; i<size; i++)
        a[i] = b[i];
}

int main(int argc, char *argv[]) {
    int a[5] = {0, 0, 0, 0, 0};
    int i;

    for (i = 0; i< 5; i++)
        scanf("%d", &a[i]);

    reverse(a, 5);

    for (i = 0; i < 5; i++)
        printf("%d\n", a[i]);

    return 0;
}
