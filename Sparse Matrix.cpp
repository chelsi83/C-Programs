#include<stdio.h>

int main() {
    // Initialize a 2D array of size 10x10
    static int arr[10][10];
    
    // Declare variables to store dimensions of the matrix and other loop counters
    int i,j,m,n;
    
    // Counter to keep find of the number of zero elements in the matrix
    int counter=0;
    
    // Take input from the user for the order (dimensions) of the matrix
    printf("Enter the order of the matrix (rows and columns)");
    scanf("%d%d",&m,&n); // m for rows, n for columns
    
    // Take input for the matrix elements
    printf("Enter the elements of the matrix");
    for(i=0;i<m;++i)
     {
        for(j=0;j<n;++j)
	 {
            scanf("%d",&arr[i][j]);
            
            // Check if the element is zero and increment the counter
            if(arr[i][j]==0) 
	    {
                ++counter;
            }
        }
    }
    
    // Display the matrix in a formatted manner
    printf("Matrix is:\n");
    for(i=0;i<m;++i)
     {
        for(j=0;j<n;++j)
	 {
            printf("%3d",arr[i][j]); // Print each element with a width of 3 characters
        }
        printf("\n"); // Move to the next line after printing each row
    }
    
    // Check if the matrix is a sparse matrix
    if(counter>((m*n)/2))
     {
        printf("The given matrix is a sparse matrix\n");
    } else {
        printf("The given matrix is not a sparse matrix\n");
    }
    
    // Print the total number of zeroes in the matrix
    printf("Number of zeroes %d\n", counter);
    
    return 0;
}

