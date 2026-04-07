#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];

// DFS function
int dfs(int node, int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfs(i, n))
                    return 1;
            }
            else if (recStack[i]) {
                return 1; // cycle found
            }
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Function to check cycle
int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e); // nodes, edges

    // initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // input edges (directed)
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}