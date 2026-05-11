//binary
#include <stdio.h>
#include <conio.h>

// Function to accept and print array
void in(int array[], int n)
{
    int i;

    printf("Enter %d integers:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Array elements are:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

// Function for binary search
void binarySearch(int array[], int n, int search)
{
    int first, last, middle;

    first = 0;
    last = n - 1;

    while(first <= last)
    {
        middle = (first + last) / 2;

        if(array[middle] < search)
        {
            first = middle + 1;
        }

        else if(array[middle] == search)
        {
            printf("%d found at location %d\n", search, middle + 1);
            return;
        }

        else
        {
            last = middle - 1;
        }
    }

    printf("%d is not found in the array\n", search);
}

void main()
{
    int n, search, array[100];

    printf("Binary Search Program\n");

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    // Function call to accept and print array
    in(array, n);

    printf("Enter value to search:\n");
    scanf("%d", &search);

    // Function call for binary search
    binarySearch(array, n, search);

    
}
