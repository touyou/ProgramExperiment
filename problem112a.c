#include <stdio.h>
#include <stdlib.h>

double dot(size_t n, const double v[], const double w[]);

int main() {
    printf("dot(2, &(double[]){-2.32, 23.3}, &(double[]){10.9, 2.5}) == %f\n", dot(2, &(double[]){-2.32, 23.3}, &(double[]){10.9, 2.5}));
    puts("ans 32.962");
    printf("dot(0, NULL, NULL) == %f\n", dot(0, NULL, NULL));
    puts("ans 0.0");
    printf("dot(6, &(double[]){0.0783, 4.57, 13.1, -5.45, 9.60, 9.07}, &(double[]){-5.85, 0.397, 2.11, 4.04, 2.20, -3.48}) == %f\n", dot(6, &(double[]){0.0783, 4.57, 13.1, -5.45, 9.60, 9.07}, &(double[]){-5.85, 0.397, 2.11, 4.04, 2.20, -3.48}));
    puts("ans -3.464365");
    return 0;
}
