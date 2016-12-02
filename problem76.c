#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char *String;
typedef struct tnode *BTree;
struct tnode {
    String key;
    String value;
    BTree left;
    BTree right;
};

BTree btree_empty();
int btree_isempty(BTree t);
BTree new_node(String key, String val);
BTree btree_insert(String key, String val, BTree t);
BTree new_tree(String key, String val, BTree left, BTree right);
BTree merge_tree(BTree base, BTree ins);
BTree btree_delete(String key, BTree t);
struct tnode *btree_search(String key, BTree t);
void print_btree(BTree t);
void btree_free(BTree t);

BTree btree_empty()
{
    /* 空木を返す。 */
    return NULL;
}

int btree_isempty(BTree t)
{
    /* `t'が空木なら0以外を、そうでないなら0を返す。 */
    if (t == NULL) return 1;
    else return 0;
}

BTree new_node(String key, String val) {
    BTree new = (BTree) malloc(sizeof(BTree));
    new->key = (String) malloc(sizeof(key));
    new->value = (String) malloc(sizeof(val));
    new->left = btree_empty();
    new->right = btree_empty();
    strcpy(new->key, key);
    strcpy(new->value, val);
    return new;
}

BTree btree_insert(String key, String val, BTree t)
{
    /*
     * 文字列`key'をキーとして、文字列`val'を二分探索木`t'に挿入し、その木を返す。
     * `key'と`val'の内容はデータベースにコピーされる。
     * 同じキーを持つ項目が既に存在する場合は、その項目を上書きする。
     */
    if (btree_isempty(t)) return new_node(key, val);
    if (strcmp(t->key, key) == 0) {
        strcpy(t->value, val);
    } else if (strcmp(t->key, key) < 0) {
        t->left = btree_insert(key, val, t->left);
    } else {
        t->right = btree_insert(key, val, t->right);
    }
    return t;
}

BTree new_tree(String key, String val, BTree left, BTree right) {
    BTree new = malloc(sizeof(BTree));
    new->left = left;
    new->right = right;
    new->key = malloc(sizeof(key) + 1);
    strcpy(new->key, key);
    new->value = malloc(sizeof(val) + 1);
    strcpy(new->value, val);
    return new;
}

BTree merge_tree(BTree base, BTree ins) {
    if (btree_isempty(ins)) return base;
    BTree new = btree_insert(ins->key, ins->value, base);
    return merge_tree(merge_tree(new, ins->left), ins->right);
}

BTree btree_delete(String key, BTree t)
{
    /*
     * 文字列`key'をキーとする項目を、二分探索木`t'から削除し、その木を返す。
     */
    if (btree_isempty(t)) return t;
    if (strcmp(t->key, key) == 0) {
        t = new_tree(t->right->key, t->right->value, merge_tree(t->left, t->right->left), t->right->right);
    } else if (strcmp(t->key, key) < 0) {
        t->left = btree_delete(key, t->left);
    } else {
        t->right = btree_delete(key, t->right);
    }
    return t;
}

struct tnode *btree_search(String key, BTree t)
{
    /*
     * 二分探索木`t'を検索し、文字列`key'をキーとするノードへのポインタを返す。
     * 見付からない場合は、NULLを返す。
     */
    if (btree_isempty(t)) return NULL;
    if (strcmp(key, t->key) == 0) return t;
    else if (strcmp(key, t->key) < 0) return btree_search(key, t->left);
    else return btree_search(key, t->right);
}

void print_btree(BTree t) {
    if (btree_isempty(t)) return;
    printf("%s: %s\n", t->key, t->value);
    printf("left---\n"); print_btree(t->left);
    printf("right---\n"); print_btree(t->right);
}

void btree_free(BTree t)
{
    /*
     * 二分探索木`t'の内容を全て消去し、メモリを解放する。
     */
    if (btree_isempty(t)) return;
    free(t->key);
    free(t->value);
    btree_free(t->left);
    btree_free(t->right);
}

int main() {
    BTree t = btree_empty();
    char cmd[100], key[100], val[100];
    while(scanf("%100s", cmd) != EOF) {
        if (strcmp(cmd, "insert") == 0) {
            scanf("%100s%100s", key, val);
            t = btree_insert(key, val, t);
            //print_btree(t);
        } else if (strcmp(cmd, "search") == 0) {
            scanf("%100s", key);
            struct tnode *res = btree_search(key, t);
            if (res == NULL) printf("(not found)\n");
            else printf("%s\n", res->value);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%100s", key);
            t = btree_delete(key, t);
            //print_btree(t);
        } else if (strcmp(cmd, "quit") == 0) {
            break;
        } else {
            printf("(unknown command)\n");
        }
    }

    if (!btree_isempty(t)) btree_free(t);

    return 0;
}
