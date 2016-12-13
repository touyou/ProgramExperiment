#include <stdio.h>
#include <stdlib.h>

int prime_factor(int n);

const int test[][2] = {
    {6, 2},
    {299, 13},
    {307, 307}
};

int main() {
    int i;
    for (i=0; i<(int)(sizeof(test)/sizeof(*test)); i++) {
        int res = prime_factor(test[i][0]);
        printf("prime_factor(%d) == %d\n",test[i][0],res);
        if (res == test[i][1]) puts("ok");
        else puts("ng");
    }
    return 0;
}

