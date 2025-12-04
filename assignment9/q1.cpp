#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int start, int n) {
    int i, node;
    for (i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while ((node = dequeue()) != -1) {
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, e, u, v, i;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("BFS starting from 0: ");
    BFS(0, n);

    return 0;
}
