#include <stdio.h>
 
void f(size_t n, unsigned long *a);
 
int main() {
    unsigned long a[100];
    int i;
    f(100, a);
    for(i = 0; i < 100; ++i) {
        printf("%lu\n", a[i]);
    }
    return 0;
}
