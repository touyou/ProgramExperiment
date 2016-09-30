#include <stdio.h>

int num;

int main() {
    scanf("%d", &num);
    printf("%d\n", num>=0?num:num*(-1));
    return 0;
}
