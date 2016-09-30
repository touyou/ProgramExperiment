#include <stdio.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int min3(int a, int b, int c) {
    return min(a, min(b, c));
}

int main(int argc, char *argv[]) {
    int x0 = 0, x1 = 0, x2 = 0;
    scanf("%d%d%d", &x0, &x1, &x2);
    printf("%d\n", min3(x0, x1, x2));
    return 0;
}
