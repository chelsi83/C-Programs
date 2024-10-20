#include <stdio.h>
int main()
 {
    int sum=0,size,i;

    // take input for array size from user
    printf("Enter array size: ");
    scanf("%d",&size);
    
    // Declare array of given size
    int a[size];

    // take input for array elements from user
    printf("Enter elements of the array:\n");
    for (i=0;i<size;i++) 
    { 
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    // Print sum of array elements
    printf("Sum of array elements = %d\n",sum); 
    return 0;
}
