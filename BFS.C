#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int g[MAX][MAX], visited[MAX];
int q[MAX];
int front = -1, rear = -1;

//vertices=m edges=n
void init_graph(int m) {
    for (int k = 0; k < m; k++) {
        visited[k] = 0;
        for (int l = 0; l < m; l++) {
            g[k][l] = 0;
        }
    }
}
void add_edge(int u, int v) {
    g[u][v] = 1;
    g[v][u] = 1;
}


void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    q[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return q[front++];
}
int bfs(int start_vertex, int m) {
    enqueue(start_vertex);
    visited[start_vertex] = 1;
    int steps=0;

    printf("Breadth First Search starting from vertex %d:\n", start_vertex);

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);
        steps++;

        for (int k = 0; k < m; k++) {
            if (g[current][k] == 1 && visited[k] == 0) {
                enqueue(k);
                visited[k] = 1;
            }
        }
    }
    printf("\n");
    return steps;
}

int main() {
    int m, n, u, v, start,steps;


    printf("Enter number of vertices: ");
    scanf("%d", &m);

    init_graph(m);

    printf("Enter number of edges: ");
    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        printf("Enter edge %d (u v): ", k + 1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    steps=bfs(start, m);
    printf("No of steps is: %d",steps);

    return 0;
}
