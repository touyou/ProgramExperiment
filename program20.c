#include <stdio.h>

int main(int argc, char *argv[]) {
    char s[9];
    int c;
    int i = 0;

    c = getchar();
    while((c != EOF) && (i < 9)) {
        s[i++] = c;
        c = getchar();
    }

    printf("%s\n", s);
    return 0;
}
