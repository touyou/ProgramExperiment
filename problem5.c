#include <stdio.h>

int a, b, c, d;

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", max(a, max(b, max(c, d))));
    return 0;
}
