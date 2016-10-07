#include <stdio.h>

int main(int argc, char *argv[]) {
    char s1[100] = "";
    char s2[100];

    int i;
    scanf("%99s", s1);

    for (i = 0; i < sizeof(s1)/sizeof(char); i++) {
        s2[i] = s1[i];
    }

    printf("%s\n", s2);

    return 0;
}
