// Program for graph traversal using DFS
// and checking whether graph is connected or not

#include <stdio.h>

int a[20][20], reach[20], n;

// function for input
void input() {
    int i, j;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// function for display
void display() {
    int i, j;

    printf("\nAdjacency Matrix:\n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// DFS function
void dfs(int v) {
    int i;

    reach[v] = 1;

    for(i = 1; i <= n; i++) {
        if(a[v][i] && !reach[i]) {
            printf("\n%d -> %d", v, i);
            dfs(i);
        }
    }
}

// function to check connectivity
void isConnected() {
    int i, count = 0;

    for(i = 1; i <= n; i++) {
        if(reach[i])
            count++;
    }

    if(count == n)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected");
}

int main() {
    int i;

    printf("DFS Traversal");

    input();

    display();

    // initialize reach array
    for(i = 1; i <= n; i++) {
        reach[i] = 0;
    }

    printf("\nDFS Traversal:\n");
    dfs(1);
    printf("\n");
    isConnected();
    return 0;
}
