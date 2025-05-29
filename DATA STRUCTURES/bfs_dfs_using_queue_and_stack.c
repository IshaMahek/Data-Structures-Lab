#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX], front = 0, rear = -1; // For BFS
int stack[MAX], top = -1;            // For DFS

void bfs(int start, int vertices) {
    front = 0; rear = -1;
    for (int i = 0; i < vertices; i++) visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");
    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int start, int vertices) {
    top = -1;
    for (int i = 0; i < vertices; i++) visited[i] = 0;

    stack[++top] = start;

    printf("DFS Traversal: ");
    while (top != -1) {
        int currentVertex = stack[top--];
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;

            for (int i = vertices - 1; i >= 0; i--) { // Reverse order for proper DFS
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, start, end, startVertex, choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &start, &end);
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1; // For undirected graphs
    }

    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    printf("Choose the traversal method:\n1. BFS\n2. DFS\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        bfs(startVertex, vertices);
    } else if (choice == 2) {
        dfs(startVertex, vertices);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
