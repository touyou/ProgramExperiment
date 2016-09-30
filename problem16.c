#include <stdio.h>

void mul(int l[][3], int r[][2], int a[][2], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            a[i][0] += l[i][j] * r[j][0];
            a[i][1] += l[i][j] * r[j][1];
        }
    }
    for (int i=0; i<2; i++) {
        printf("%d %d\n", a[i][0], a[i][1]);
    }

}

int l[2][3];
int r[3][2];
int a[2][2];

int main() {
    

    for (int i=0; i<2; i++) for (int j=0; j<3; j++) scanf("%d", &l[i][j]);
    for (int i=0; i<3; i++) for (int j=0; j<2; j++) scanf("%d", &r[i][j]);
    mul(l, r, a, 2);

    return 0;
}
