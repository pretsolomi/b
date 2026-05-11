// Program to implement Fractional Knapsack using Greedy Method

#include <stdio.h>
#include <conio.h>

void in(float weight[], float profit[], int num, float *capacity);
void sort(float weight[], float profit[], float ratio[], int num);
void knapsack(int n, float weight[], float profit[], float capacity);

void in(float weight[], float profit[], int num, float *capacity)
{
    int i;

    printf("\nEnter the weights and profits of each object:\n");

    for(i = 0; i < num; i++)
    {
        printf("Object %d (weight profit): ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", capacity);
}

void sort(float weight[], float profit[], float ratio[], int num)
{
    int i, j;
    float temp;

    // Calculate ratio
    for(i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort in descending order of ratio
    for(i = 0; i < num; i++)
    {
        for(j = i + 1; j < num; j++)
        {
            if(ratio[i] < ratio[j])
            {
                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // Swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }
}

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    float u;
    int i;

    u = capacity;

    for(i = 0; i < n; i++)
        x[i] = 0.0;

    for(i = 0; i < n; i++)
    {
        if(weight[i] > u)
            break;

        x[i] = 1.0;
        tp = tp + profit[i];
        u = u - weight[i];
    }

    // Take fractional part
    if(i < n)
    {
        x[i] = u / weight[i];
        tp = tp + (x[i] * profit[i]);
    }

    printf("\nResult Vector:\n");

    for(i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
    }

    printf("\nMaximum Profit = %f", tp);
}

int main()
{
    float weight[20], profit[20], ratio[20], capacity;
    int num;

    printf("Greedy Method - Fractional Knapsack\n");

    printf("\nEnter number of objects: ");
    scanf("%d", &num);

    in(weight, profit, num, &capacity);

    sort(weight, profit, ratio, num);

    knapsack(num, weight, profit, capacity);

    return 0;
}
