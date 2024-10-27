#include <stdio.h>

int main() 
{
    int n;

    // take input from user for the number of elements
    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size n
    int *ptr = arr; // Pointer to the array

    // Input elements into the array
    printf("Enter %d elements\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i); // Store elements in array using pointer
    }

    // Print the elements using the pointer
    printf("The elements in the array are\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i)); // Access elements in array using pointer
    }
    
    printf("\n");
    return 0;
}

