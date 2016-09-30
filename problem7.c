#include <stdio.h>

int n, cnt;
int x[100000];

int main() {
    scanf("%d", &n);
    cnt = 0;
    while (n > 0) {
        x[cnt] = n % 10;
        n /= 10;
        cnt++;
    }
    int flag = 0;
    for (int i=0; i<cnt; i++) {
        if (flag==0&&x[i]!=0) {
            flag = 1;
        }
        if (flag==1) {
            printf("%d", x[i]);
        }
    }
    puts("");
    return 0;
}
