#include <stdio.h>

int isYes(char *s) {
    return s[0] == 'y' && s[1] == 'e' && s[2] == 's' && s[3] == '\0';
}

int main(int argc, char *argv[]) {
    char s[100] = "";

    scanf("%99s", s);

    if (isYes(s)) puts("OK");
    else puts("NG");
    return 0;
}
