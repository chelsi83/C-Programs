#include <stdio.h>
int main() 
{
    int n, i, j, isUnique;

    // take input from  the user for the number of elements in the array
    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n]; // Array declaration
    printf("Enter the elements of the array\n");
    for (i=0;i<n;i++) 
    {
        scanf("%d", &arr[i]);
    }

    // print unique elements
    printf("Unique elements in the array are");
    for (i=0;i<n;i++)
     {
        isUnique = 1;  // Assume element is unique

        // Check if element is repeated in the array
        for (j=0;j<n;j++) 
	{
            if (i!=j && arr[i]==arr[j])
	     {
                isUnique = 0;  // Element is not unique
                break;
            }
        }

        // Print the element if it is unique
        if (isUnique) 
	{
            printf("%d ", arr[i]);
        }
    }
    return 0;  // End of program
}

