#include <stdio.h>

void printReverse(int *arr, int size) 
{
    // Start from the last element and move backwards
    for (int i = size - 1; i >= 0; i--)
     {
        printf("%d ", *(arr + i)); // Access each element using pointer arithmetic
    }
    printf("\n"); // New line after printing all elements
}

int main() 
{
    int arr[100], n;
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Read array elements
    printf("Enter %d elements", n);
    for (int i = 0; i < n; i++)
     {
        scanf("%d", arr + i); // Store elements using pointer arithmetic
    }
    // Print array elements in reverse order
    printf("Array in reverse order");
    printReverse(arr, n);

    return 0;
}

