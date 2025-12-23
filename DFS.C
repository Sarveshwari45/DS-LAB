#include <stdio.h>

int g[20][20], vi[20], n;

void dfs(int u) {
    printf("%d ", u);
    vi[u] = 1;
    for (int i = 0; i < n; i++) {
        if (g[u][i] && !vi[i]) {
            dfs(i);
        }
    }
}
int main() {
    int e, u, v, s;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);


    for (int i = 0; i < n; i++) {
        vi[i] = 0;
        for (int j = 0; j < n; j++) {
            g[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}
