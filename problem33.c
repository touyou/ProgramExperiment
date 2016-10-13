#include <stdio.h>
#include <stdlib.h>

char *getstr()
{
    char *buf;
    int x;

    buf = malloc(100);
 
    x = scanf("%99s", buf);
 
    return (x == EOF) ? NULL : buf;
}
 
int main(int argc, char *argv[])
{
    char *s[5];
    int i;
 
    for (i = 0; i < 5; i++) {
        s[i] = getstr();
    }
 
    for (i = 4; 0 <= i; i--) {
        if (s[i] != NULL) {
            printf("%s\n", s[i]);
            free(s[i]);
        }
    }
 
    return 0;
}
