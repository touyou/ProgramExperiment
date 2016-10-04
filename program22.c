#include <stdio.h>

int main(int argc, char *argv[]) {
    char s1[100] = "";

    int i;
    scanf("%99s", s1);
    for (i = sizeof(s1)/sizeof(char)-2; i >= 0; i--) {
        if (s1[i] != '\0') printf("%c", s1[i]);
    }
    puts("");

    return 0;
}
