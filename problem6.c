#include <stdio.h>

int a, b, c;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b == c) {
        puts("A");
    } else if (a == b || b == c || c == a) {
        puts("B");
    } else {
        puts("C");
    }
}
