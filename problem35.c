#include <stdio.h>
#include <stdlib.h>
 
struct wizard {
    char *name;
    int hp;
    int mp;
};
 
int main(int argc, char *argv[])
{
    struct wizard *p;
 
    p = malloc(sizeof(struct wizard));
    p->name = malloc(sizeof(char)*10);
    p->hp = malloc(sizeof(int));
    p->mp = malloc(sizeof(int));
    if (p == NULL) exit(1);

    scanf("%9s%d%d", p->name, &p->hp, &p->mp);

    if (p->mp >= 10) {
        p->hp += 100;
        p->mp -= 10;
    }
 
    printf("%s\n%d\n%d\n", p->name, p->hp, p->mp);
 
    free(p);
 
    return 0;
}
