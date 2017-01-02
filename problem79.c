#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct vertex {
    char *name;
    struct edge *adj;
    struct vertex *left;
    struct vertex *right;
} vertex;

typedef struct edge {
    struct vertex *targetp;
    int weight;
    struct edge *next;
} edge;

int main() {

}
