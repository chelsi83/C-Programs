#include <stdio.h>
int main() {
int arr[100], pos, n, i;
      // Input number of elements
printf("Enter number of elements in the array");
    scanf("%d", &n);

    // Input elements of the array
    printf("Enter %d elements", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
 // Input position to delete
    printf("Enter a location to delete the element");
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
     {
        printf("Deletion not possible\n");
    }
     else 
     {
        // Shift elements to the left
        for (i = pos - 1; i < n - 1; i++)
	 {
            arr[i] = arr[i + 1];
         }
        n--;

        // declare result array after deletion
        printf("Array after deletion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        
    }

    return 0;
}

