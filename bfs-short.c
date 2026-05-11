// BFS Traversal using Adjacency Matrix

#include <stdio.h>

int main() 
{
    int a[10][10], visited[10] = {0};
    int q[10], front = 0, rear = -1;
    int n, i, start, current;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Start BFS
    visited[start] = 1;
    q[++rear] = start;

    printf("BFS Traversal: ");

    while(front <= rear)
    {
        current = q[front++];
        printf("%d ", current);

        for(i = 0; i < n; i++)
        {
            // If connected and not visited
            if(a[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    }

    return 0;
}