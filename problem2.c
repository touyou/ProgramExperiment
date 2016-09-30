#include <stdio.h>

int x, y;

int main() {
    scanf("%d%d", &x, &y);
    printf("%f\n", (double)x/(double)y*100.0);
    return 0;
}
