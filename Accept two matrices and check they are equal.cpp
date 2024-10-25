#include <stdio.h>

int main()
 {
	 // Variable to store if matrices are equal
    
    int rows, cols, i, j, isEqual = 1; 
    
    
    // take input from user for matrix dimensions
    printf("Enter the number of rows and columns of the matrices");
    scanf("%d %d", &rows, &cols);
    
    int mat1[rows][cols], mat2[rows][cols];
    
    // take input from user elements of the first matrix
    printf("Enter elements of the first matrix\n");
    for (i = 0; i < rows; i++)
     {
        for (j = 0; j < cols; j++)
	 {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    
    // take input from user for elements of the second matrix
    printf("Enter elements of the second matrix\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
	{
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    
    // Compare elements of both matrices
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++)
	 {
            if (mat1[i][j] != mat2[i][j]) 
	    {
                isEqual = 0; // Set to 0 if any elements differ
                break;       // Break out of the inner loop
            }
        }
        if (!isEqual) break; // Break out of the outer loop if not equal
    }
    
    // Output result based on comparison
    if (isEqual)
     {
        printf("The matrices are equal.\n");
    } else 
    {
        printf("The matrices are not equal.\n");
    }

    return 0;
}

