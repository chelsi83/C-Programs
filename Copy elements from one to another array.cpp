#include <stdio.h>
int main()
 {
    int n,i;

    //  take input from the user for the number of elements in the array
    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr1[n], arr2[n];  // Declare two arrays of size n
    printf("Enter the elements of the first array\n");
    for (i=0;i<n;i++)
     {
        scanf("%d", &arr1[i]);
    }

    // Copy elements from arr1 to arr2
    for (i=0;i<n;i++)
     {
        arr2[i]=arr1[i];
    }
    printf("Elements of the second array\n");
    for (i=0;i<n;i++) 
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}

