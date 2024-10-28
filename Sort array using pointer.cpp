#include <stdio.h>

void sortArray(int *arr, int size) 
{
    // Bubble Sort with pointers
    for (int i = 0; i < size - 1; i++)
     {
        for (int j = 0; j < size - i - 1; j++) 
	{
            // Compare and swap using pointer arithmetic
            if (*(arr + j) > *(arr + j + 1)) 
	    {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
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
        scanf("%d", arr + i); // Use pointer arithmetic to read elements
    }

    // Sort the array
    sortArray(arr, n);

    // Display the sorted array
    printf("Sorted array");
    for (int i = 0; i < n; i++)
     {
        printf("%d ", *(arr + i)); // Access elements using pointer arithmetic
    }
    printf("\n");

    return 0;
}

