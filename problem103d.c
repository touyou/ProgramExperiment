#include <stdio.h>
#include <stdlib.h>

int maxof2(int x, int y);

const int test[][3] = {
    {2, 4, 4},
    {-3, 5, 5},
    {4, -10, 4},
    {1, 100, 100}
};

int main() {
    int i;
    for (i = 0; i < (int)(sizeof(test)/sizeof(*test)); i++) {
        int r = maxof2(test[i][0], test[i][1]);
        printf("maxof2(%d, %d) == %d\n", test[i][0], test[i][1], r);
        if (r == test[i][2]) puts("ok");
        else puts("ng");
    }
    return 0;
}
