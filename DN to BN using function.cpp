#include <stdio.h>

void decimalToBinary(int n) 
{
    // Array to store binary number
    int binaryNum[32];
    
    // Counter for binary array
    int i = 0;
    while (n > 0)
     {
        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Printing binary array in reverse order
    printf("Binary equivalent");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    printf("\n");
}

int main()
 {
    int num;
    printf("Enter a decimal number");
    scanf("%d", &num);

    if (num == 0)
     {
        printf("Binary equivalent0\n");
    } else 
    {
        decimalToBinary(num);
    }

    return 0;
}

