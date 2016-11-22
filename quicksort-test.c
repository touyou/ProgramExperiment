#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *String;
typedef struct lnode *List;
struct lnode {
    String data;
    List next;
};

List list_empty() {
    return NULL;
}

int list_isempty(List l) {
    if (l == NULL || l->data == NULL) {
        return 1;
    } else {
        return 0;
    }
}

List list_cons(String s, List l) {
    List new = malloc(sizeof(List));
    new->data = malloc(strlen(s));
    strcpy(new->data, s);
    new->next = l;
    return new;
}

void list_free(List l) {
    if (l->next != NULL) {
        list_free(l->next);
    }
    free(l->data);
    free(l);
}

void list_putl(List l) {
    while (!list_isempty(l)) {
        printf("%s\n", l->data);
        l = l->next;
    }
}

void my_sort(List l) {
    // quick sort
    if (list_isempty(l)) return;
    if (l->data == NULL) return;
    printf("debug: %s\n", l->data);
    String pivot = malloc(strlen(l->data));
    strcpy(pivot, l->data);
    List a = malloc(sizeof(List));
    List b = malloc(sizeof(List));
    List next = malloc(sizeof(List));
    next = l->next;
    printf("first: %s\n", next->data);
    while(!list_isempty(next)) {
        printf("loop\n");
        if (strcmp(next->data, pivot) <= 0) {
            a = list_cons(next->data, a);
        } else {
            b = list_cons(next->data, b);
        }
        next = next->next;
    }
    printf("a sort\n");
    my_sort(a);
    printf("b sort\n");
    my_sort(b);
    next = a->next;
    while(!list_isempty(next)) {
        next = next->next;
    }
    List new = malloc(sizeof(List));
    new->data = malloc(sizeof(pivot));
    strcpy(new->data, pivot);
    new->next = b;
    next->next = new;
    l = a;
    list_free(b);
    list_free(a);
}

int main(int argc, char *argv[]) {
    List l;
    char buf[100] = "";

    l = list_empty();

    while (scanf("%99s", buf) != EOF) {
        l = list_cons(buf, l);
        buf[0] = '\0';
    }

    my_sort(l);

    list_putl(l);

    list_free(l);

    return 0;
}
