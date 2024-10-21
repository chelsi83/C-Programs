#include<stdio.h>

int main()
{
    // Initialize array of size 9
    int arr[9] = {1, 3, 3, 4, 9, 8, 9, 6, 4};
    
    // Declare variables
    int i, j, k, n = 9;
    
    // Loop through the array to remove duplicates
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)  // Start from the next element
        {
            if(arr[i] == arr[j])  // Check duplicate elements
            {
                for(k = j; k < n - 1; k++)  // Shift elements to the left
                {
                    arr[k] = arr[k + 1];
                }
                n--;  // Reduce array size
                j--;  // Adjust index after removing duplicate
            }
        }
    }
    
    // Print the array without duplicates
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

