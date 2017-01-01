#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef char *String;
typedef struct tnode *BTree;
struct tnode {
    String key;
    int value;
    BTree left;
    BTree right;
};

BTree btree_empty();
int btree_isempty(BTree t);
BTree new_node(String key, int val);
BTree btree_insert(String key, int val, BTree t);
BTree new_tree(String key, int val, BTree left, BTree right);
BTree merge_tree(BTree base, BTree ins);
BTree btree_delete(String key, BTree t);
struct tnode *btree_search(String key, BTree t);
void print_btree(BTree t);
void btree_free(BTree t);
int min(int a, int b) {
    return a > b ? b : a;
}

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

BTree new_node(String key, int val) {
    BTree new = malloc(sizeof(struct tnode));
    new->key = malloc(sizeof(key));
    new->value = val;
    strcpy(new->key, key);
    new->left = btree_empty();
    new->right = btree_empty();
    return new;
}

BTree btree_insert(String key, int val, BTree t)
{
    /*
     * 文字列`key'をキーとして、文字列`val'を二分探索木`t'に挿入し、その木を返す。
     * `key'と`val'の内容はデータベースにコピーされる。
     * 同じキーを持つ項目が既に存在する場合は、その項目を上書きする。
     */
    if (btree_isempty(t)) return new_node(key, val);
    if (strcmp(t->key, key) == 0) {
        t->value = val;
    } else if (strcmp(t->key, key) < 0) {
        t->left = btree_insert(key, val, t->left);
    } else {
        t->right = btree_insert(key, val, t->right);
    }
    return t;
}

BTree new_tree(String key, int val, BTree left, BTree right) {
    BTree new = malloc(sizeof(struct tnode));
    new->left = left;
    new->right = right;
    new->key = malloc(sizeof(key) + 1);
    strcpy(new->key, key);
    new->value = val;
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
        if (btree_isempty(t->right))
            t = t->left;
        else
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
    else if (strcmp(t->key, key) < 0) return btree_search(key, t->left);
    else return btree_search(key, t->right);
}

void btree_free(BTree t)
{
    /*
     * 二分探索木`t'の内容を全て消去し、メモリを解放する。
     */
    if (btree_isempty(t)) return;
    free(t->key);
    btree_free(t->left);
    btree_free(t->right);
}

int hash(String key) {
    int ret = 0;
    for (int i=0; i<strlen(key); i++) ret += (int)(key[i]);
    return ret % 30;
}

int main() {
    int graph[1000][1000];
    char name[1000][1000];
    for (int i=0; i<1000; i++) for (int j=0; j<1000; j++) graph[i][j] = INT_MAX;
    int pnum = 1, cost;
    char start[1000], end[1000], temp1[1000], temp2[1000];
    scanf("%s%s", start, end);
    BTree *table = malloc(sizeof(struct tnode) * 30);
    int h = hash(start);
    table[h] = btree_insert(start, 0, table[h]);
    h = hash(end);
    table[h] = btree_insert(end, 1, table[h]);
    strcpy(name[0], start);
    strcpy(name[1], end);
    while (scanf("%s%s%d", temp1, temp2, &cost) != EOF) {
        int h1 = hash(temp1), h2 = hash(temp2);
        struct tnode *a = btree_search(temp1, table[h1]);
        struct tnode *b = btree_search(temp2, table[h2]);
        int anum, bnum;
        if (a == NULL) {
            table[h1] = btree_insert(temp1, ++pnum, table[h1]);
            strcpy(name[pnum], temp1);
            anum = pnum;
        } else {
            anum = a->value;
        }
        if (b == NULL) {
            table[h2] = btree_insert(temp2, ++pnum, table[h2]);
            strcpy(name[pnum], temp2);
            bnum = pnum;
        } else {
            bnum = b->value;
        }
        graph[anum][bnum] = min(graph[anum][bnum], cost);
        graph[bnum][anum] = min(graph[bnum][anum], cost);
    }
    // ここでグラフを辿っていく
    int res = 0;
    cost = INT_MAX;
    for (int i=0; i<1000; i++) {
        if (cost > graph[0][i]) {
            cost = graph[0][i];
            res = i;
        }
    }
    printf("%s\n", name[res]);
}
