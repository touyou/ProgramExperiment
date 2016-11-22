#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char *String;
typedef struct lnode *List;
struct lnode {
    int data;
    List next;
};

List list_empty()
{
    /* 空リストを返す。 */
    return NULL;
}
 
int list_isempty(List l)
{
    /* `l'が空リストなら0以外を、そうでないなら0を返す。 */
    if (l == NULL) {
        return 1;
    } else {
        return 0;
    }
}
 
List list_cons(int s, List l)
{
    /*
     * リスト`l'の先頭に文字列`s'を要素として追加したリストを返す。
     * 文字列はリストの内部にコピーされる。
     * 必要なメモリはmallocやcallocで確保する。
     */
    List new = malloc(sizeof(List));
    new->data = s;
    new->next = l;
    return new;
}
 
void list_free(List l)
{
    /*
     * リスト`l'の使用しているメモリを全て解放する。
     * この関数を呼び出して以降、`l'を使用してはいけない。
     */
    if (l->next != NULL) {
        list_free(l->next);
    }
    free(l);
}

List stack_push(List l, int n) {
    return list_cons(n, l);
}

int stack_read(List l) {
    return l->data;
}

List stack_pop(List l) {
    return l->next;
}

List calc_add(List l) {
    int a = stack_read(l);
    int b = stack_read(stack_pop(l));
    return stack_push(stack_pop(stack_pop(l)), a+b);
}

List calc_sub(List l) {
    int a = stack_read(l);
    int b = stack_read(stack_pop(l));
    return stack_push(stack_pop(stack_pop(l)), b-a);
}

List calc_mul(List l) {
    int a = stack_read(l);
    int b = stack_read(stack_pop(l));
    return stack_push(stack_pop(stack_pop(l)), a*b);
}

int main(int argc, char *argv[])
{
    List st;
    char cmd[10];

    st = list_empty();

    while ((scanf("%9s", cmd) != EOF) && (cmd[0] != '=')) {
        if (isdigit(cmd[0])) {
            st = stack_push(st, atoi(cmd));
        } else if (cmd[0] == '+') {
            st = calc_add(st);
        } else if (cmd[0] == '-') {
            st = calc_sub(st);
        } else if (cmd[0] == '*') {
            st = calc_mul(st);
        } else {
            printf("(unknown command)\n");
        }
        cmd[0] = '\0';
    }
    if (! list_isempty(st)) {
        printf("%d\n", stack_read(st));
    }

    list_free(st);

    return 0;
}
