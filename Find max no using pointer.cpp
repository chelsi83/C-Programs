#include <stdio.h>

int main()
 {
    int a, b;
    int *p1, *p2; // Declare pointers for two numbers
    
    // Take input from user for two numbers
    printf("Enter the first number");
    scanf("%d", &a);
    printf("Enter the second number");
    scanf("%d", &b);
    
    // Assign the addresses of a and b to p1 and p2
    p1 = &a;
    p2 = &b;
    
    // Compare values pointed by p1 and p2
    if (*p1 > *p2)
     {
        printf("The maximum number is%d\n", *p1);
    }
     else 
    {
        printf("The maximum number is%d\n", *p2);
    }
    
    return 0;
}

