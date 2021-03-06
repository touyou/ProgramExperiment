#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char *substr(char *s, int *pos)
{
    int i = 0;
    char *p;
 
    p = malloc(strlen(s) + 1);
    strcpy(p, s);

    while (p[i] != '\0') {
        if (p[i] == 'a')
            break;
        i++;
    }

    *pos = i;

    return p + i;
}
 
int main()
{
    char buf[100] = "";
    char *s[5];
    int pos[5];
    int i;
 
    for (i = 0; i < 5; i++) {
        scanf("%99s", buf);
        s[i] = substr(buf, &pos[i]);
        buf[0] = '\0';
    }
 
    for (i = 4; 0 <= i; i--) {
        printf("%s\n", s[i]);
        /* 以下の行を入れるとエラーになる。 */
        free(s[i] - pos[i]);
    }
    return 0;
}
