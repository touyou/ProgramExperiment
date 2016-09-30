#include <stdio.h>
int ver[4][4];
int res;

int main() {
    for (int i=0; i<4; i++) for (int j=0; j<4; j++)
        scanf("%d", &ver[i][j]);
    res = 0;
    for (int i=0; i<4; i++) {
        res += ver[i][i];
    }
    printf("%d\n", res);
    return 0;
}
