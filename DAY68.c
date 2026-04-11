#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Graph using adjacency matrix
int adj[MAX][MAX];
int indegree[MAX];
int n;

// Queue implementation
int queue[MAX];
int front = 0, rear = -1;

// Enqueue
void enqueue(int v) {
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front > rear;
}

// Kahn's Algorithm
void topologicalSort() {
    // Step 1: Compute in-degree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order:\n");

    // Step 3: Process queue
    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        // Reduce indegree of adjacent vertices
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }

        count++;
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("\nGraph has a cycle! Topological sort not possible.\n");
    }
}

// Driver code
int main() {
    n = 6;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Add edges
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort();

    return 0;
}