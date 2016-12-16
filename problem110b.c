#include <stdio.h>
#include <stdlib.h>

int fib(int n);

const int test[][2] = {
    {5, 5},
    {15, 610},
    {42, 267914296}
};

int main() {
    for (int i=0; i<(int)(sizeof(test)/sizeof(*test)); i++) {
        int res = fib(test[i][0]);
        printf("fib(%d) == %d\n", test[i][0], res);
        if (res == test[i][1]) puts("ok");
        else puts("ng");
    }
    return 0;
}
