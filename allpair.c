// Program for All-Pairs Shortest Path using Floyd's Algorithm

#include <stdio.h>
#define INF 999

int p[10][10], n;

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function for input
void input() {
    int e, u, v, w, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize matrix
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {

            if(i == j)
                p[i][j] = 0;
            else
                p[i][j] = INF;
        }
    }

    // Input edges
    for(i = 1; i <= e; i++) {

        printf("Enter edge (u v weight): ");
        scanf("%d %d %d", &u, &v, &w);

        p[u][v] = w;
    }
}

// Function to display matrix
void display() {
    int i, j;

    for(i = 1; i <= n; i++) {

        for(j = 1; j <= n; j++) {

            if(p[i][j] == INF)
                printf("999\t");
            else
                printf("%d\t", p[i][j]);
        }

        printf("\n");
    }
}

// Function to calculate shortest paths
void floyds() {
    int i, j, k;

    for(k = 1; k <= n; k++) {

        for(i = 1; i <= n; i++) {

            for(j = 1; j <= n; j++) {

                p[i][j] = min(p[i][j],
                              p[i][k] + p[k][j]);
            }
        }
    }
}

void main() {

    int i, j;

    printf("All-Pairs Shortest Path using Floyd's Algorithm\n");

    input();

    printf("\nInput Matrix:\n");
    display();

    floyds();

    printf("\nShortest Path Matrix:\n");
    display();

    printf("\nShortest Paths:\n");

    for(i = 1; i <= n; i++) {

        for(j = 1; j <= n; j++) {

            if(i != j) {

                printf("\n<%d,%d> = ", i, j);

                if(p[i][j] == INF)
                    printf("No Path");
                else
                    printf("%d", p[i][j]);
            }
        }
    }

    
}
