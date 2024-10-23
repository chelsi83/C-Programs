#include <stdio.h>

int main() {
    int n, i, j, count;

    // take input from the user for the number of elements in the array
    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n];  // Declare the array
    printf("Enter the elements of the array\n");
    for (i=0;i<n;i++)
     {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the frequency of each element
    printf("Element | Frequency\n");
    for (i=0;i<n;i++)
     {
        count = 1;
        if (arr[i] != -1)
	 { 
	  // If the element is not yet counted
            for (j=i+1;j<n;j++) 
	    {
                if (arr[i]==arr[j]) 
		{
                    count++;
                    arr[j]=-1;  // Mark the element as counted
                }
            }
            printf("   %d    |    %d\n", arr[i], count);  // Print the frequency
        }
    }

    return 0;
}

