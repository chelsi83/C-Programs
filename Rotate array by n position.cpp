#include <stdio.h>

int rotateArray(int arr[], int size, int n) 
{
    int temp[size]; // Temporary array to store rotated elements
    
    n = n % size; // Normalize rotation if n > size

    // Copy last n elements to the beginning of temp
    for (int i = 0; i < n; i++) 
    {
        temp[i] = arr[size - n + i];
    }

    // Copy the first (size - n) elements after the last n elements in temp
    for (int i = n; i < size; i++) 
    {
        temp[i] = arr[i - n];
    }

    // Copy temp back to arr
    for (int i = 0; i < size; i++)
     {
        arr[i] = temp[i];
    }
}

int main() 
{
    int size, n;

    // Input array size
    printf("Enter the size of the array");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter the elements of the array\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input number of rotations
    printf("Enter the number of positions to rotate");
    scanf("%d", &n);

    // Rotate array
    rotateArray(arr, size, n);

    // Print rotated array
    printf("Rotated array\n");
    for (int i = 0; i < size; i++)
     {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

