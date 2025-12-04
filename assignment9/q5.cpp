#include <stdio.h>

#define INF 999
#define MAX 50

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix (999 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = graph[src][i];

    visited[src] = 1;

    for (int count = 1; count < n; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Shortest distances from %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);

    return 0;
}
