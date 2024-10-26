#include <stdio.h>

int main() 
{
    int num = 10;        // Declare an integer variable
    int *ptr = &num;     // Declare a pointer and assign it the address of num

    // Display the value of num and the address it occupies
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);

    // Display the value of the pointer (address it holds) and the value at that address
    printf("Value of pointer ptr (address of num): %p\n", ptr);
    printf("Value pointed to by ptr (value of num): %d\n", *ptr);

    return 0;
}

