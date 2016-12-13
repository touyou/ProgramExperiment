#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double saturate(double x);

static int fp_equiv(double x, double y) {
      return (isnan(x) && isnan(y)) || (x == y && signbit(x) == signbit(y));
}

const double test[][2] = {
    {-3.4, 0.0},
    {0.375, 0.375},
    {1.5, 1.0},
    {-5.78, 0.0},
    {-0.0, 0.0},
    {-INFINITY, 0.0},
    {INFINITY, 1.0},
    {NAN, NAN}
};

int main() {
    for (int i=0; i<(int)(sizeof(test)/sizeof(*test)); i++) {
        double r = saturate(test[i][0]);
        printf("saturate(%f) == %f\n", test[i][0], r);
        if (fp_equiv(test[i][1], r)) puts("ok");
        else puts("ng");
    }
    return 0;
}
