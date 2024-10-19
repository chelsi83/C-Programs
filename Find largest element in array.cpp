#include <stdio.h>
int main() 
{
    int i, n;
    int arr[100];
    printf("Enter total number of elements: ");
    scanf("%d", &n);

    // Read the elements into the array
    for(i=0;i<n;++i)
     {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]); 
    }

    // Initialize largest with the first element
    int largest=arr[0];

    // Loop using to find the largest element
    for(i=1;i<n;i++)
     {
        if(arr[i]>largest)
	 {
            largest=arr[i]; 
        }
    }
     // Print the largest element
    printf("Largest element = %d\n", largest);
    return 0;
}

