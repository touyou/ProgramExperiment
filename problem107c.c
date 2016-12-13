#include <stdio.h>

int fresh(void);

int main() {
    for (int i=0; i<10; i++) {
        int temp = fresh();
        printf("fresh()=%d\n", temp);
        if (temp == i) puts("ok");
        else puts("ng");
    }
    return 0;
}
