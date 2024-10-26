#include <stdio.h>

int main() 
{
    int num = 15;           // Declare an integer variable and assign a value
    int *ptr;               // Declare a pointer to an integer

    // Use the & operator to get the address of num and assign it to ptr
    ptr = &num;

    // Display the address of num using &
    printf("Address of num using & operator: %p\n", &num);

    // Display the value of ptr, which holds the address of num
    printf("Address stored in pointer ptr: %p\n", ptr);

    // Use the * operator to get the value at the address stored in ptr
    printf("Value at the address stored in ptr (value of num): %d\n", *ptr);

    // Modify the value of num using the pointer
    *ptr = 25;
    printf("New value of num after modifying through pointer: %d\n", num);

    return 0;
}

