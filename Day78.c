#include <stdio.h>
#include <limits.h>

#define MAX 1000

int graph[MAX][MAX];

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 1; v <= n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int parent[MAX];   // stores MST
    int key[MAX];      // minimum weight to connect
    int mstSet[MAX];   // included in MST

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;   // start from node 1
    parent[1] = -1;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}