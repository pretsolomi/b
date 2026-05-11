// Program for Dijkstra Shortest Path Algorithm

#include<stdio.h>

#define infinity 999

// Function for input
void input(int cost[20][20], int *n, int *v) {
    int i, j;

    printf("DIJKSTRA\n");

    printf("Enter number of nodes: ");
    scanf("%d", n);

    printf("\nEnter the cost matrix:\n");

    for(i = 1; i <= *n; i++) {
        for(j = 1; j <= *n; j++) {

            scanf("%d", &cost[i][j]);

            // Replace 0 with infinity except diagonal
            if(i != j && cost[i][j] == 0)
                cost[i][j] = infinity;
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d", v);
}

// Dijkstra Function
void dij(int n, int v, int cost[20][20], int dist[]) {

    int i, u, count, w, flag[20], min;

    for(i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    dist[v] = 0;
    flag[v] = 1;

    count = 2;

    while(count <= n) {

        min = infinity;

        // Find minimum distance node
        for(w = 1; w <= n; w++) {

            if(dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;
            }
        }

        flag[u] = 1;
        count++;

        // Update distances
        for(w = 1; w <= n; w++) {

            if((dist[u] + cost[u][w] < dist[w]) && !flag[w]) {

                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

// Function for display
void display(int n, int v, int dist[]) {

    int i;

    printf("\nShortest Paths:\n");

    for(i = 1; i <= n; i++) {

        if(i != v)

            printf("%d -> %d , Cost = %d\n", v, i, dist[i]);
    }
}

// Main Function
int main() {

    int n, v;
    int cost[20][20], dist[20];

    input(cost, &n, &v);

    dij(n, v, cost, dist);

    display(n, v, dist);

    return 0;
}
