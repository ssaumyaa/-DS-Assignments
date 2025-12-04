#include <stdio.h>

#define MAX 100

int adj2[MAX][MAX];
int visited2[MAX];

void DFS(int v, int n) {
    int i;
    visited2[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj2[v][i] == 1 && !visited2[i])
            DFS(i, n);
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
        adj2[u][v] = adj2[v][u] = 1;
    }

    printf("DFS starting from 0: ");
    DFS(0, n);

    return 0;
}
