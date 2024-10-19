#include <stdio.h>

int main() {
    int n;
    
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Increase size by 1 
    int arr[n + 1]; 
    int i;

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos;
    printf("Enter the position to insert the new element", n + 1);
    scanf("%d", &pos);

    int ele;
    printf("Enter the element to insert: ");
    scanf("%d", &ele);

    // Check for valid position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid Input");
    } 
    else
     {
        // Shift elements to the right to make space for the new element
        for (i = n - 1; i >= pos - 1; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = ele; // Insert the new element

        // Print the updated array
        printf("Array after insertion\n");
        for (i = 0; i <= n; i++)
	 { 
	 // Print n + 1 elements
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}

