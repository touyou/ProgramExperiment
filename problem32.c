#include <stdio.h>
 
struct wizard {
    char name[10];
    int hp;
    int mp;
};
 
/* 関数の定義を修正。 */
void healing(struct wizard *x)
{
    if (x->mp >= 10) {
        x->hp += 100;
        x->mp -= 10;
    }
}
 
int main(int argc, char *argv[])
{
    struct wizard x;
 
    scanf("%9s%d%d", x.name, &x.hp, &x.mp);
 
    /* この行も書き換える。 */
    healing(&x);
 
    printf("%s\n%d\n%d\n", x.name, x.hp, x.mp);
 
    return 0;
}
