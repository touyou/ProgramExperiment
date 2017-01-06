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

void printVertex(Vertex *v) {
    if (v == NULL) return;
    printf("name: %s\n", v->name);
    Edge *adj = v->adj;
    int cnt = 0;
    puts("adj");
    while (adj != NULL) {
        printf("%s ", adj->targetp->name);
        adj = adj->next;
    }
    puts("");
    printVertex(v->left);
    printVertex(v->right);
}
void printEdge(Edge *adj) {
    if (adj == NULL) return;
    printf("%s ",adj->targetp->name);
    printEdge(adj->next);
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
    if (strcmp(target->name, e->targetp->name) == 0) {
        e->weight = e->weight > weight ? weight : e->weight;
    } else {
        e->next = insertEdge(target, weight, e->next);
    }
    return e;
}
Vertex *updateVertex(char name[1000], char targetName[1000], int weight, Vertex *v) {
    Vertex *s = searchVertex(name, v);
    Vertex *t = searchVertex(targetName, v);
    s->adj = insertEdge(t, weight, s->adj);
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
Vertex *minVertex(int dist, Vertex *v) {
    if (v == NULL) return NULL;
    if (v->visited) {
        Vertex *leftMin = minVertex(dist, v->left);
        Vertex *rightMin = minVertex(dist, v->right);
        if (leftMin == NULL && rightMin == NULL) return NULL;
        else if (leftMin == NULL) return rightMin;
        else if (rightMin == NULL) return leftMin;
        else return leftMin->cost < rightMin->cost ? leftMin : rightMin;
    } else {
        if (v->cost < dist) {
            Vertex *leftMin = minVertex(v->cost, v->left);
            Vertex *rightMin = minVertex(v->cost, v->right);
            if (leftMin == NULL && rightMin == NULL) return v;
            else if (leftMin == NULL) return rightMin->cost < v->cost ? rightMin : v;
            else if (rightMin == NULL) return leftMin->cost < v->cost ? leftMin : v;
            else if (leftMin->cost < rightMin->cost) return leftMin->cost < v->cost ? leftMin : v;
            else return rightMin->cost < v->cost ? rightMin : v;
        } else {
            Vertex *leftMin = minVertex(dist, v->left);
            Vertex *rightMin = minVertex(dist, v->right);
            if (leftMin == NULL && rightMin == NULL) return NULL;
            else if (leftMin == NULL) return rightMin;
            else if (rightMin == NULL) return leftMin;
            else return leftMin->cost < rightMin->cost ? leftMin : rightMin;
        }
    }
}

void dijkstra(char start[1000], char end[1000], Vertex *v) {
    Vertex *e = searchVertex(end, v);
    if (e == NULL) {
        puts("data structure error");
        return;
    }
    e->cost = 0;
    while (1) {
        Vertex *ne = minVertex(INT_MAX, v);
        if (ne == NULL) break;
        if (ne->cost == INT_MAX) break;
        ne->visited = 1;
        Edge *adj = ne->adj;
        while (adj != NULL) {
            if (!adj->targetp->visited) {
                int newDist = ne->cost + adj->weight;
                if (newDist < adj->targetp->cost) {
                    adj->targetp->cost = newDist;
                    adj->targetp->prev = ne;
                }
            }
            adj = adj->next;
        }
    }
    Vertex *s = searchVertex(start, v);
    if (s->prev == NULL) {
        puts("(no route)");
    } else {
        while (s->prev != NULL) {
            printf("%s\n", s->name);
            s = s->prev;
        }
        printf("%s\n", e->name);
    }
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
    // printVertex(vertex);
    dijkstra(start, end, vertex);
    freeVertex(vertex);
    return 0;
}
