#include <stdio.h>
int main() 
{
    int n, max, min;

    //take input from the user for the number of elements
    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n];

    // take input from the user for the elements of the array
    printf("Enter %d elements\n", n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with the first element of the array
    max = min = arr[0];

    // Loop through the array to find max and min
    for(int i = 1; i < n; i++) 
    {
        if(arr[i] > max)
	 {
            max = arr[i]; // Update max if current element is greater
        }
        if(arr[i] < min) 
	{
            min = arr[i]; // Update min if current element is smaller
        }
    }
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}

