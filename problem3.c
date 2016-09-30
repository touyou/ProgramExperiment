#include <stdio.h>

int x, y;

int main() {
    scanf("%d%d", &x, &y);
    if ((double)x/(double)y*100.0-x*100/y >= 0.5) {
        printf("%d\n",x*100/y+1);
    } else {
        printf("%d\n",x*100/y);
    }
    return 0;
}

