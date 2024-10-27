#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *x, int *y) 
{
    int temp = *x; // Store the value at address x in temp
    *x = *y;       // Copy the value at address y to address x
    *y = temp;     // Copy temp to address y
}

int main() 
{
    int a, b;
    
    // Input two numbers from the user
    printf("Enter the first number");
    scanf("%d", &a);
    printf("Enter the second number");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    
    // Call swap function to swap the values of a and b
    swap(&a, &b);

    printf("After swapping: a = %d, b = %d\n", a, b);
    
    return 0;
}

