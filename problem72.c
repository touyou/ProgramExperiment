#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *String;
typedef struct lnode *List;
struct lnode {
    String data;
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
 
List list_cons(String s, List l)
{
    /*
     * リスト`l'の先頭に文字列`s'を要素として追加したリストを返す。
     * 文字列はリストの内部にコピーされる。
     * 必要なメモリはmallocやcallocで確保する。
     */
    List new = malloc(sizeof(List));
    new->data = malloc(strlen(s));
    strcpy(new->data, s);
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
    free(l->data);
    free(l);
}
 
void list_putl(List l)
{
    while (! list_isempty(l)) {
        printf("%s\n", l->data);
        l = l->next;
    }
}
 
int main(int argc, char *argv[])
{
    List l;
    char buf[100] = "";
 
    l = list_empty();
 
    while (scanf("%99s", buf) != EOF) {
        l = list_cons(buf, l);
        buf[0] = '\0';
    }
 
    list_putl(l);
 
    list_free(l);
 
    return 0;
}
