#include <stdio.h>
char c;
int cnt;
int main() {
    cnt = 0;
    while ((c = getchar()) != EOF) {
        if (c == 'a') cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
