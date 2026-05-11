#include <stdio.h>

#define INF 999

int main() {
    int n, cost[20][20], visited[20] = {0};
    int i, j, min, minCost = 0, edges = 0;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for no edge):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i!= j)
                cost[i][j] = INF;
        }

    visited[0] = 1; // start from vertex 0
    printf("\nMST Edges:\n");

    while (edges < n - 1) {
        min = INF;

        // find the smallest edge between visited and unvisited vertices
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);
        minCost = minCost + min;
        visited[v] = 1;
        edges++;
    }

    printf("\nTotal MST Cost = %d\n", minCost);
    return 0;
}
