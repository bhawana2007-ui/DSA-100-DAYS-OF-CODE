#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAX];

typedef struct {
    int vertex, dist;
} HeapNode;

HeapNode heap[MAX * MAX];
int heapSize = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(HeapNode val) {
    heap[++heapSize] = val;
    int i = heapSize;

    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int left = 2 * i, right = 2 * i + 1, smallest = i;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return top;
}

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    dist[source] = 0;
    push((HeapNode){source, 0});

    while (heapSize > 0) {
        HeapNode current = pop();
        int u = current.vertex;

        if (current.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push((HeapNode){v, dist[v]});
            }
            temp = temp->next;
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}