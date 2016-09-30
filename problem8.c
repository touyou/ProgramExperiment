#include <stdio.h>

int x, y;

int main() {
    scanf("%d%d", &x, &y);
    for (int i=x; i<=y; i++) {
        if (i%3==0&&i%5==0) puts("FizzBuzz");
        else if (i%3==0) puts("Fizz");
        else if (i%5==0) puts("Buzz");
        else printf("%d\n", i);
    }
    return 0;
}
