#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort3(int *a, int *b, int *c) {
    if (*a > *b) swap(a, b);
    if (*a > *c) swap(a, c);
    if (*b > *c) swap(b, c);
}

int main(int argc, char *argv[]) {
    int x[3] = {0, 0, 0};
    int i;

    for (i = 0; i < 3; i++)
        scanf("%d", &x[i]);

    sort3(&x[0], &x[1], &x[2]);

    for (i = 0; i < 3; i++)
        printf("%d\n", x[i]);

    return 0;
}
