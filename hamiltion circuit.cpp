#include <stdio.h>

#define V 10 // Maximum number of vertices

void printSolution(int path[]);

int isSafe(int v, int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

int hamCycleUtil(int graph[V][V], int path[], int pos, int vertices) {
    if (pos == vertices) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(path);
            return 1;
        } else
            return 0;
    }

    for (int v = 1; v < vertices; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1, vertices) == 1)
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

void hamCycle(int graph[V][V], int vertices) {
    int *path = new int[vertices];
    for (int i = 0; i < vertices; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamCycleUtil(graph, path, 1, vertices) == 0) {
        printf("\nSolution does not exist");
        return;
    }
}

void printSolution(int path[]) {
    printf("Solution Exists: Following is one Hamiltonian Cycle:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf(" %d\n", path[0]);
}

int main() {
    int graph[V][V];
    int vertices;

    printf("Enter the number of vertices (maximum %d): ", V);
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamCycle(graph, vertices);
    return 0;
}

