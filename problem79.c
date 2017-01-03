#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// -- typedef
typedef char *String;
typedef struct Vertex {
    String name;
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
    int v;
    int cost;
} Pair;
typedef struct Heap {
    struct Pair *data;
    int last;
    int size;
} Heap;

// -- Util
void swapPair(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

// -- Heap
void insert(Heap *heap, Pair val) {
    Pair* data = heap->data;
    if (heap->last + 1 > heap->size) return;
    ++(heap->last);
    data[heap->last] = val;
    int i = heap->last;
    while (i > 0) {
        if (data[(i-1)/2].cost > data[i].cost) {
            swapPair(&data[(i-1)/2], &data[i]);
            i = (i-1)/2;
        } else {
            return;
        }
    }
    return;
}
Pair deleteMin(Heap *heap) {
    Pair* data = heap->data;
    Pair val;
    if (heap->last < 0) return val;
    val = data[0];
    data[0] = data[heap->last];
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
    return val;
}

// -- 

void dijkstra() {}

int main() {
    char start[1000], end[1000], inp1[1000], inp2[1000];
    char name[1000][1000];
    int cost;
    scanf("%s%s", start, end);
    while (scanf("%s%s%d", inp1, inp2, &cost) != EOF) {
        
    }
    dijkstra();
    return 0;
}
