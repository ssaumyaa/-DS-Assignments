#include <stdio.h>

#define MAX 30

int parent[MAX];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void union_set(int x, int y) {
    int p = find(x);
    int q = find(y);
    parent[q] = p;
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    int edges[e][3];

    for (int i = 0; i < e; i++)
        scanf("%d%d%d", &edges[i][0], &edges[i][1], &edges[i][2]);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < e - 1; i++)
        for (int j = i + 1; j < e; j++)
            if (edges[i][2] > edges[j][2]) {
                int temp0 = edges[i][0], temp1 = edges[i][1], temp2 = edges[i][2];
                edges[i][0] = edges[j][0]; edges[i][1] = edges[j][1]; edges[i][2] = edges[j][2];
                edges[j][0] = temp0; edges[j][1] = temp1; edges[j][2] = temp2;
            }

    int total = 0;
    printf("Edges in MST:\n");

    for (int i = 0; i < e; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];

        if (find(u) != find(v)) {
            union_set(u, v);
            printf("%d -- %d = %d\n", u, v, w);
            total += w;
        }
    }

    printf("Total weight = %d\n", total);
    return 0;
}
