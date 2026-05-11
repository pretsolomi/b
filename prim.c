// Prim's Algorithm - Minimum Spanning Tree
#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], n;

// Function to print matrix
void printMatrix()
{
    int i, j;

    printf("\nThe matrix is :\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(cost[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}

// Function for Prim's Algorithm
void prim()
{
    int i, j;
    int startVertex, endVertex;
    int k;
    int nr[MAX];
    int temp;
    int minimumCost = 0;

    int tree[MAX][3];

    // Find minimum edge
    temp = INF;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(cost[i][j] < temp && cost[i][j] != 0)
            {
                temp = cost[i][j];
                startVertex = i;
                endVertex = j;
            }
        }
    }

    // First edge in MST
    tree[0][0] = startVertex;
    tree[0][1] = endVertex;
    tree[0][2] = temp;

    minimumCost = temp;

    // Initialize near array
    for(i = 0; i < n; i++)
    {
        if(cost[i][startVertex] < cost[i][endVertex])
            nr[i] = startVertex;
        else
            nr[i] = endVertex;
    }

    nr[startVertex] = -1;
    nr[endVertex] = -1;

    // Remaining edges
    for(i = 1; i < n - 1; i++)
    {
        temp = INF;

        for(j = 0; j < n; j++)
        {
            if(nr[j] != -1 && cost[j][nr[j]] < temp)
            {
                temp = cost[j][nr[j]];
                k = j;
            }
        }

        tree[i][0] = k;
        tree[i][1] = nr[k];
        tree[i][2] = cost[k][nr[k]];

        minimumCost += tree[i][2];

        nr[k] = -1;

        // Update near array
        for(j = 0; j < n; j++)
        {
            if(nr[j] != -1 && cost[j][k] < cost[j][nr[j]])
            {
                nr[j] = k;
            }
        }
    }

    // Output
    printf("\nMinimum Spanning Tree:\n");

    for(i = 0; i < n - 1; i++)
    {
        printf("%d %d %d\n",
               tree[i][0],
               tree[i][1],
               tree[i][2]);
    }

    printf("\nMinimum Cost = %d\n", minimumCost);
}

int main()
{
    int i, j;

    printf("Prim's Algorithm\n");

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF except diagonal
            if(i != j && cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }

    // Print matrix
    printMatrix();

    // Call Prim's Algorithm
    prim();

    return 0;
}
