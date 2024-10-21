#include <stdio.h>

int main() 
{
	//declare variables
    int i, n;
    int arr[100]; // Array initialize to store elements 100

    //taken input from user
    printf("Enter total number of elements");
    scanf("%d", &n);

    // Read the elements into the array
    for(i=0;i<n;++i) 
    {
        printf("Enter number %d",i + 1);
        scanf("%d", &arr[i]); 
    }

    // Initialize smallest with the first element
    int smallest=arr[0];

    // Loop to find the smallest element
    for(i=1;i<n;i++) 
    {
        if(arr[i]<smallest) 
        {
            smallest=arr[i]; 
        }
    }

    // Print the smallest element
    printf("Smallest element = %d\n", smallest);

    return 0;
}

