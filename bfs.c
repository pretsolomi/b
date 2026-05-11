// Program for Graph Traversal using BFS (0-based indexing)

#include <stdio.h>

int a[20][20], q[20], visited[20];
int n, i, j, f = 0, r = -1;

void input()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display()
{
    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// BFS function
void bfs(int v)
{
    // Mark starting vertex as visited
    visited[v] = 1;
    // Insert into queue
    q[++r] = v;

    // Run until queue becomes empty
    while(f <= r)
    {
        // Remove from queue
        int current = q[f++];

        // Print current node
        printf("%d ", current);

        // Check all adjacent vertices
        for(i = 0; i < n; i++)
        {
            // If connected and not visited
            if(a[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;

                // Add into queue
                q[++r] = i;
            }
        }
    }
}

int main()
{
    int v, connected = 1;

    printf("BFS Traversal\n");

    input();

    display();

    // Initialize visited array
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // Starting vertex
    printf("\nEnter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &v);

    printf("\nBFS Traversal is:\n");

    bfs(v);

    // Check connectivity
    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            connected = 0;
            break;
        }
    }

    if(connected)
    {
        printf("\n\nGraph is Connected\n");
    }
    else
    {
        printf("\n\nGraph is Not Connected\n");
    }

    return 0;
}
