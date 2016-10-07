#include <stdio.h>

int isSame(char *s1, char *s2) {
    for (int i=0; i<sizeof(s1)/sizeof(char); i++) {
        if (s1[i] != s2[i]) return 0;
    }
    return 1;
}

int main() {
    char s1[100];
    char s2[100];

    scanf("%99s%99s", s1, s2);

    if (isSame(s1, s2)) puts("OK");
    else puts("NG");
}
