#include <stdio.h>

int main() 
{
    int array[100], search, n, i;

    // take input number of elements from user
    printf("Enter number of elements");
    scanf("%d", &n);

    // take Input array elements from user
    printf("Enter %d integers", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    // take Input the number to search from user
    printf("Enter number to search: ");
    scanf("%d", &search);

    // Search for the number
    for (i = 0; i < n; i++)
     {
        if (array[i] == search)
	 { 
	  // If found
            printf("%d is present at position %d\n", search, i + 1);
            return 0;  // Exit the program after finding the number
        }
    }

    // If not found
    printf("%d is not present in the array\n", search);

    return 0;
}

