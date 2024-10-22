#include <stdio.h>

int main() 
{
    int matrix[2][2];
    int determinant;

    // Input elements of the 2x2 matrix
    printf("Enter the elements of the 2x2 matrix\n");
    for (int i=0;i<2;i++)
     {
        for (int j=0;j<2;j++)
	 {
            printf("Element at [%d][%d]",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the determinant of the matrix
    determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    // Display the determinant
    printf("The determinant of the matrix is %d\n", determinant);

    return 0;
}

