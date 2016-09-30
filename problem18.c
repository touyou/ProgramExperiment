#include <stdio.h>

int n;

int fib(int a, int b, int cnt) {
    if (cnt == n) return b;
    return fib(b, a+b, cnt+1);
}

int main() {
    scanf("%d", &n);
    if (n == 1) {
        puts("1");
        return 0;
    }
    printf("%d\n", fib(1, 1, 2));
    return 0;
}
