/* Originally written by とうよう and 改ざんされ by Ho */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// -- typedef
typedef char *String;
typedef struct Vertex {
    char name[1000];
    int cost;
    int visited;
    struct Vertex *prev;
    struct Edge *adj;
    struct Vertex *left;
    struct Vertex *right;
} Vertex;
typedef struct Edge {
    struct Vertex *targetp;
    int weight;
    struct Edge *next;
} Edge;
typedef struct Pair {
    char v[1000];
    int cost;
} Pair;
typedef struct Heap {
    struct Pair *data;
    int last;
    int size;
} Heap;

// -- Util
void swapPair(Pair *a, Pair *b) {
    int tempNum = a->cost;
    char temp[1000];
    strcpy(temp, a->v);

    a->cost = b->cost;
    strcpy(a->v, b->v);

    b->cost = tempNum;
    strcpy(b->v, temp);
}
void copyPair(Pair *t, Pair *s) {
    t->cost = s->cost;
    strcpy(t->v, s->v);
}

// -- Heap
Heap *insertHeap(Heap *heap, Pair *val) {
    Pair* data = heap->data;
    /* if (heap->last + 1 > heap->size) return heap; */
    if (heap->last + 1 >= heap->size) return heap; /* 応急処置 */
    ++(heap->last);
    copyPair(&data[heap->last], val);
    int i = heap->last;
    while (i > 0) {
        if (data[(i-1)/2].cost > data[i].cost) {
            swapPair(&data[(i-1)/2], &data[i]);
            i = (i-1)/2;
        } else {
            return heap;
        }
    }
    return heap;
}
Heap *deleteMinHeap(Heap *heap) {
    Pair* data = heap->data;
    Pair *val = malloc(sizeof(Pair));
    if (heap->last < 0) return heap;
    copyPair(val, &data[0]);
    copyPair(&data[0], &data[heap->last]);
    --(heap->last);
    int i = 0;
    while (i < heap->last / 2) {
        if (data[i].cost > data[i*2+1].cost) {
            if (data[i*2+2].cost < data[i*2+1].cost) {
                swapPair(&data[i], &data[i*2+2]);
                i = i * 2 + 2;
            } else {
                swapPair(&data[i], &data[i*2+1]);
                i = i * 2 + 1;
            }
        } else if (data[i].cost > data[i*2+2].cost) {
            swapPair(&data[i], &data[i*2+2]);
            i = i * 2 + 2;
        } else {
            break;
        }
    }
    return heap;
}
int isEmptyHeap(Heap *heap) {
    /* return heap == NULL; */
    return heap->last < 0; /* 応急処置 */
}
void freeHeap(Heap *heap) {
    free(heap->data);
    free(heap);
}

// -- Make Tree
Vertex *singleVertex(char name[1000]) {
    Vertex *vertex = malloc(sizeof(Vertex));
    strcpy(vertex->name, name);
    vertex->cost = INT_MAX;
    vertex->visited = 0;
    vertex->prev = NULL;
    vertex->left = NULL;
    vertex->right = NULL;
    vertex->adj = NULL;
    return vertex;
}

Vertex *insertVertex(char name[1000], Vertex *v) {
    if (v == NULL) return singleVertex(name);
    if (strcmp(name, v->name) > 0) {
        v->right = insertVertex(name, v->right);
    } else if (strcmp(name, v->name)) {
        v->left = insertVertex(name, v->left);
    }
    return v;
}
Vertex *searchVertex(char name[1000], Vertex *v) {
    if (v == NULL) return NULL;
    if (strcmp(name, v->name) == 0) return v;
    else if (strcmp(name, v->name) > 0) return searchVertex(name, v->right);
    else return searchVertex(name, v->left);
}
Edge *insertEdge(Vertex *target, int weight, Edge *e) {
    if (e == NULL) {
        Edge *new = malloc(sizeof(Edge));
        new->targetp = target;
        new->weight = weight;
        new->next = NULL;
        return new;
    }
    if (strcmp(target->name, e->targetp->name) == 0) e->weight = e->weight > weight ? weight : e->weight;
    else e->next = insertEdge(target, weight, e->next);
    return e;
}
Vertex *updateVertex(char name[1000], char targetName[1000], int weight, Vertex *v) {
    Vertex *s = searchVertex(name, v);
    Vertex *t = searchVertex(targetName, v);
    if (s == NULL) s = singleVertex(name); /* ??? */
    if (t == NULL) t = singleVertex(targetName); /* ??? */
    /* v->adj = insertEdge(t, weight, s->adj); */
    s->adj = insertEdge(t, weight, s->adj); /* 応急処置 */
    return v;
}
void freeEdge(Edge *e) {
    if (e == NULL) return;
    freeEdge(e->next);
    free(e);
}
void freeVertex(Vertex *v) {
    if (v == NULL) return;
    freeEdge(v->adj);
    freeVertex(v->left);
    freeVertex(v->right);
}

void dijkstra(char start[1000], char end[1000], Vertex *v) {
    Vertex *e = searchVertex(end, v);
    if (e == NULL) {
        puts("(no route)");
        return;
    }
    e->cost = 0;
    Heap *heap = malloc(sizeof(Heap));
    heap->data = malloc(sizeof(Pair) * 1000);
    /* heap->last = 0; */
    heap->last = -1; /* 応急処置 */
    heap->size = 1000;
    Pair *p = malloc(sizeof(Pair));
    strcpy(p->v, end);
    p->cost = 0;
    heap = insertHeap(heap, p);
    while (!isEmptyHeap(heap)) {
        Pair *next = malloc(sizeof(Pair));
        copyPair(next, &heap->data[0]);
        Vertex *nv = searchVertex(next->v, v);
        heap = deleteMinHeap(heap); /* 応急処置 */
        if (nv->visited) continue;
        nv->visited = 1;
        Edge *ne = nv->adj;
        while (ne != NULL) {
            /* Vertex *next = nv->adj->targetp; */
            Vertex *next = ne->targetp; /* 応急処置 */
            /* if (nv->cost + nv->adj->weight < next->cost) { */
            if (nv->cost + ne->weight < next->cost) { /* 応急処置 */
                /* next->cost = nv->cost + nv->adj->weight; */
                next->cost = nv->cost + ne->weight; /* 応急処置 */
                next->prev = nv;
                Pair *np = malloc(sizeof(Pair));
                strcpy(np->v, next->name);
                np->cost = next->cost;
                heap = insertHeap(heap, np);
                free(np); /* なんとなく */
            }
            ne = ne->next;
        }
        free(next); /* なんとなく */
    }
    Vertex *s = searchVertex(start, v);
    if (s->prev == NULL) {
        puts("(no route)");
    } else {
        while (s->prev != NULL) {
            printf("%s\n", s->name);
            s = s->prev;
        }
        printf("%s\n", p->v); /* 応急処置 */
    }
    freeHeap(heap);
}

int main() {
    char start[1000], end[1000], inp1[1000], inp2[1000];
    int cost;
    scanf("%s%s", start, end);
    Vertex *vertex = singleVertex(start);
    vertex = insertVertex(end, vertex);
    while (scanf("%s%s%d", inp1, inp2, &cost) != EOF) {
        vertex = insertVertex(inp1, vertex);
        vertex = insertVertex(inp2, vertex);
        vertex = updateVertex(inp1, inp2, cost, vertex);
        vertex = updateVertex(inp2, inp1, cost, vertex);
    }
    dijkstra(start, end, vertex);
    freeVertex(vertex);
    return 0;
}
