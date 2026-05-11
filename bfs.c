//program for graph traversal using bfs
#include <stdio.h>

int a[20][20], q[20], visited[20];
int n, i, j, f = 0, r = -1;

void input()
{
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter graph data in matrix form:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display()
{
    printf("\nAdjacency Matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void bfs(int v)
{
    visited[v] = 1;
    q[++r] = v;

    while(f <= r)
    {
        int current = q[f++];

        printf("%d\t", current);

        for(i = 1; i <= n; i++)
        {
            if(a[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main()
{
    int v, connected = 1;

    printf("BFS\n");

    input();
    display();

    // initialize visited array
    for(i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);

    printf("\nThe nodes which are reachable are:\n");

    bfs(v);

    // check connectivity
    for(i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            connected = 0;
            break;
        }
    }

    if(connected)
    {
        printf("\nBFS is possible\n");
    }
    else
    {
        printf("\nBFS is not possible\n");
    }

    return 0;
}
