#include <stdio.h>
#include <stdlib.h>

void swap_gt(int *x, int *y);

const int test[][4] = {
    {1, 2, 1, 2},
    {10, 2, 2, 10}
};

int main() {
    int i;
    for (i = 0; i < (int)(sizeof(test)/sizeof(*test)); i++) {
        int x, y;
        x = test[i][0]; y = test[i][1];
        swap_gt(&x, &y);
        printf("swap_gt(%d, %d) -> x = %d, y = %d\n", test[i][0], test[i][1], x, y);
        if (x == test[i][2] && y == test[i][3]) puts("ok");
        else puts("ng");
    }
    return 0;
}
