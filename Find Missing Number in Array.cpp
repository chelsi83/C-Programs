#include <stdio.h>
int findMissingNumber(int arr[], int n)
 {
    // Calculate the sum of the first n natural numbers using the formula n*(n+1)/2
    int totalSum = (n * (n + 1)) / 2;
    
    // Initialize a variable to store the sum of array elements
    int arraySum = 0;
    
    // Loop through the array and calculate the sum of the elements
    for (int i = 0; i < n - 1; i++) 
    {
        arraySum += arr[i];
    }
    return totalSum - arraySum;
}

int main()
 {
    int n;
    
    // take input from the user for the size of the array
    printf("Enter the size of the array");
    scanf("%d", &n);
    
    // Declare an array of size n-1 because one number is missing
    int arr[n-1];
    
    // take input from the user to input the elements of the array
    printf("Enter %d elements of the array\n", n-1, n);
    for (int i = 0; i < n-1; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    // Call the function to find the missing number
    int missingNumber = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missingNumber);
    
    return 0; 
}

