#include <stdio.h>

int main()
 {
    int arr[5]; // Declare integer type array of size 5
    int i,j,temp; // Declare loop variables and a temporary variable for swapping

    // Take input from user for array elements
    printf("Enter 5 array elements");
    for(i=0;i<5;i++) 
    {
    	// Read each element into the array
        scanf("%d",&arr[i]);  
    }

    // Sort input elements in ascending order (bubble sort logic)
    for(i=0;i<5;i++)
     {
        for(j=0;j<5-i-1;j++)
	 {  

            if (arr[j]>arr[j+1])
	     {
                // Swap arr[j] and arr[j + 1]
                temp=arr[j];//Store arr[j] in temporary variable
                arr[j]=arr[j+1]; // Assign arr[j + 1] to arr[j]
                arr[j+1]=temp;// Assign temporary value to arr[j + 1]
            }
        }
    }

    // Print sorted array elements
    printf("Sorted array elements\n");
    for(i=0;i<5;i++)
     {
        printf("%d\n",arr[i]);  
    }
    return 0;
}

