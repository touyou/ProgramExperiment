#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char *triple_copy(char *s)
{
    char *ss;
    char *sss;
 
    /* この辺りを修正する。 */
    ss = malloc(200);
    sss = malloc(300);
    if ((ss == NULL) || (sss == NULL)) exit(1);
 
    strcpy(ss, s);
    strcpy(sss, s);
    strcat(ss, s);
    strcat(sss, ss);
 
    free(ss);
 
    return sss;
}
 
int main(int argc, char *argv[])
{
    char buf[100];
    char *s;
 
    while (scanf("%99s", buf) != EOF) {
        s = triple_copy(buf);
        printf("%s\n", s);
        free(s);
    }
 
    return 0;
}
