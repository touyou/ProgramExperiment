#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned) time(NULL));

    int cnt = 0;

    for (int i=0; i<1000000; i++) {
        double x = ((double)rand()/(double)RAND_MAX)*2.0-1.0;
        double y = ((double)rand()/(double)RAND_MAX)*2.0-1.0;

        if (x*x+y*y < 1.0) cnt++;
    }

    printf("%f\n", 4.0*cnt/1000000.0);
    return 0;
}
