#include <stdio.h>

int main() 
{
    int size, i, j, isIdentity = 1; // Variable to check if matrix is identity

    // take input from user for matrix size (must be square)
    printf("Enter the size of the square matrix");
    scanf("%d", &size);

    int matrix[size][size];

    // take input from user for elements of the matrix
    printf("Enter elements of the matrix\n");
    for (i = 0; i < size; i++)
     {
        for (j = 0; j < size; j++) 
	{
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);

            // Check conditions for identity matrix
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
	     {
                isIdentity = 0; // Not an identity matrix
            }
        }
    }

    // Output result
    if (isIdentity)
     {
        printf("The matrix is an identity matrix\n");
    }
     else 
    {
        printf("The matrix is not an identity matrix\n");
    }

    return 0;
}

