#include <stdio.h>

int main()
 {
    int num = 20;              // Declare an integer variable and assign a value
    int *p;                    // Declare an integer pointer
    int **pp;                  // Declare a pointer to a pointer

    // Assign the address of num to pointer p
    p = &num;

    // Assign the address of pointer p to pointer pp
    pp = &p;

    // Display the original value of num
    printf("Original value of num: %d\n", num);

    // Accessing the value of num using pointer p
    printf("Value of num using pointer p: %d\n", *p);

    // Accessing the value of num using pointer to pointer pp
    printf("Value of num using pointer to pointer pp: %d\n", **pp);

    // Modifying the value of num using pointer p
    *p = 30;
    printf("\nValue of num after modifying through pointer p: %d\n", num);

    // Modifying the value of num using pointer to pointer pp
    **pp = 40;
    printf("Value of num after modifying through pointer to pointer pp: %d\n", num);

    return 0;
}

