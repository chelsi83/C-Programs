#include <stdio.h>
int main()
 {
    int n, i, j = 0, k = 0;

    // take input from the user the number of elements in the array
    printf("Enter the number of elements");
    scanf("%d", &n);
    // Declare arrays for input, even, and odd numbers
    int arr[n], even[n], odd[n];  

    // Input the elements of the array
    printf("Enter the elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Store each element in the array
    }

    // Separate the array into even and odd numbers
    for (i = 0; i < n; i++) 
    {
    	// If the number is even
        if (arr[i] % 2 == 0)
	 {  
            even[j++] = arr[i]; // Add to the even array and increment j
        } 
        // If the number is odd
	else
	 {                
            odd[k++] = arr[i];  // Add to the odd array and increment k
        }
    }

    // Print the even numbers
    printf("\nEven numbers:\n");
    for (i = 0; i < j; i++)
     {
        printf("%d ", even[i]);
    }

    // Print the odd numbers
    printf("\nOdd numbers:\n");
    for (i = 0; i < k; i++) 
    {
        printf("%d ", odd[i]);
    }

    return 0;
}

