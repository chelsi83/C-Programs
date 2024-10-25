#include <stdio.h>

int main()
 {
    int array[100], search, n, low, high, mid;

    //take input the number of elements from the user
    printf("Enter number of elements");
    scanf("%d", &n);

    //take input sorted array elements from the user
    printf("Enter %d sorted integers", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    // take input the number to search for from the user
    printf("Enter number to search");
    scanf("%d", &search);

    // Set initial values for binary search
    low = 0;
    high = n - 1;

    // Perform binary search
    while (low <= high) 
    {
        mid = (low + high) / 2;  // Find the middle index

        if (array[mid] == search) 
	{  // If element found at mid
            printf("%d is present at position %d.\n", search, mid + 1);
            return 0;  // Exit as the element is found
        }
        else if (array[mid] < search)  // Search in the right half
            low = mid + 1;
        else  // Search in the left half
            high = mid - 1;
    }

    // If the element is not found
    printf("%d is not present in the array.\n", search);

    return 0;
}

