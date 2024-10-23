#include <stdio.h> 

#define SIZE 3 // Define the size of the matrix (3x3)

void displayUpperTriangular(int matrix[SIZE][SIZE], int size)
 {
    // Function to display the upper triangular matrix
    printf("Upper Triangular Matrix:\n");
    
    // Iterate through rows
    for (int i = 0; i < size; i++) 
    {
        // Iterate through columns
        for (int j = 0; j < size; j++)
	 {
            // Check if it's part of the upper triangle (i <= j)
            if (i <= j) 
	    {
                printf("%d ", matrix[i][j]); // Print the element if in the upper triangle
            }
	     else 
	     {
                printf("0 ");
            }
        }
        printf("\n"); // New line after each row
    }
}

int main() {
    // Initialize a 3x3 matrix with sample values
    int matrix[SIZE][SIZE] =
     {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Display the original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++)
	 {
            printf("%d ", matrix[i][j]); // Print each element of the matrix
        }
        printf("\n"); // New line after each row
    }

    // Call function to display the upper triangular matrix
    displayUpperTriangular(matrix, SIZE);

    return 0; 
}

