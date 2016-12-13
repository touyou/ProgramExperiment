#include <stdio.h>
 
void f() {
    fputs("Hello, world!", stderr);
    fflush(stderr);
}
