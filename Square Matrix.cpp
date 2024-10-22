#include <stdio.h>
int main() 
{
    int n,i,j;

    // take input from the user for the size of the square matrix
    printf("Enter the size of the square matrix");
    scanf("%d", &n);

    // Declare a 2D array (matrix)
    int matrix[n][n];

    // Input elements into the matrix
    printf("Enter the elements of the matrix\n");
    for (i=0;i<n;i++)
     {
        for (j=0;j<n;j++)
	 {
            printf("Element at [%d][%d]",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("The matrix is\n");
    for (i=0;i<n;i++)
     {
        for (j=0;j<n;j++)
	 {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

