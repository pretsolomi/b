// Quick Sort in C

#include <stdio.h>

void quick(int a[], int low, int high)
{
    int i = low, j = high;
    int pivot = a[(low + high) / 2];
    int temp;

    while(i <= j)
    {
        while(a[i] < pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }

    if(low < j)
        quick(a, low, j);

    if(i < high)
        quick(a, i, high);
}

int main()
{
    int a[] = {5, 2, 9, 1, 7};
    int n = 5, i;

    quick(a, 0, n - 1);

    printf("Sorted array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}