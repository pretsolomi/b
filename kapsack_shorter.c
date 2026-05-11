// Program to implement Fractional Knapsack using Greedy Method

#include <stdio.h>

int main()
{
    float weight[20], profit[20], ratio[20];
    float x[20] = {0};   // Stores fraction of each object taken
    float capacity, totalProfit = 0;

    int n, i, j;

    // Step 1: Input number of objects
    printf("Enter number of objects: ");
    scanf("%d", &n);

    // Step 2: Input weight and profit
    printf("\nEnter weight and profit of each object:\n");

    for(i = 0; i < n; i++)
    {
        printf("Object %d (weight profit): ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);

        // Calculate profit/weight ratio
        ratio[i] = profit[i] / weight[i];
    }

    // Step 3: Input knapsack capacity
    printf("\nEnter knapsack capacity: ");
    scanf("%f", &capacity);

    // Step 4: Sort objects by ratio in descending order
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                float temp;

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

    // Step 5: Apply Greedy Method
    for(i = 0; i < n; i++)
    {
        // If whole object can be taken
        if(weight[i] <= capacity)
        {
            x[i] = 1.0;

            totalProfit = totalProfit + profit[i];

            capacity = capacity - weight[i];
        }
        else
        {
            // Take fractional part
            x[i] = capacity / weight[i];

            totalProfit = totalProfit + (x[i] * profit[i]);

            break;
        }
    }

    // Step 6: Display result
    printf("\nFraction of objects taken:\n");

    for(i = 0; i < n; i++)
    {
        printf("Object %d = %.2f\n", i + 1, x[i]);
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}