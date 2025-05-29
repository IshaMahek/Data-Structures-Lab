#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void DFS_Stack(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited array

    stack[++top] = start; // Push the start vertex
    printf("DFS Traversal: ");

    while (top != -1) { // While the stack is not empty
        int vertex = stack[top--]; // Pop the top vertex

        if (!visited[vertex]) {
            printf("%d ", vertex);
            visited[vertex] = 1;

            // Push all unvisited neighbors to the stack
            for (int i = n - 1; i >= 0; i--) { // Reverse order for correct traversal
                if (adj[vertex][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

void main() {
    int ver, edges, start, end, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &ver);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < ver; i++) {
        for (int j = 0; j < ver; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter Edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &start, &end);
        adj[start][end] = 1;
    }

    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    DFS_Stack(startVertex, ver);
}
