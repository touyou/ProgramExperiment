#include <stdio.h>

int main(int argc, char *argv[]) {
    void *p;
    int x;

    p = &x;
    printf("%p\n", (char *) p + 1);
    printf("%p\n", (int *) p + 1);
    printf("%p\n", (int (*)[4]) p + 1);

    return 0;
}
