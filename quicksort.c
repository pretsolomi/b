// Quick Sort Program in C
#include <stdio.h>
int n;
// Function declarations
void inputArray(int a[]);
void displayArray(int a[]);
void quickSort(int a[], int left, int right);

int main()
{
    int a[100];
    printf("QUICK SORT\n");
    inputArray(a);
    printf("\nArray Before Sorting:\n");
    displayArray(a);
    quickSort(a, 0, n - 1);
    printf("\nArray After Sorting:\n");
    displayArray(a);

    return 0;
}
// Function for input
void inputArray(int a[])
{
    int i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}
// Function for display
void displayArray(int a[])
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}

// Quick Sort Function
void quickSort(int a[], int left, int right)
{
    int i, j, pivot, temp;
    if(left < right)
    {
        pivot = a[left];
        i = left + 1;
        j = right;

        while(i <= j)
        {
            // Find element greater than pivot
            while(i <= right && a[i] <= pivot)
            {
                i++;
            }
            // Find element smaller than pivot
            while(a[j] > pivot)
            {
                j--;
            }
            // Swap if needed
            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Place pivot in correct position
        temp = a[left];
        a[left] = a[j];
        a[j] = temp;

        // Recursive calls
        quickSort(a, left, j - 1);
        quickSort(a, j + 1, right);
    }
}
