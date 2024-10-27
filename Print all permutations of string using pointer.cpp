#include <stdio.h>
#include <string.h>

// Function to swap two characters using pointers
void swap(char *x, char *y)
 {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void permute(char *str, int left, int right)
 {
 	// Base case: if left index equals right index
    if (left == right) 
    { 
    // Print the current permutation
        printf("%s\n", str); 
    } 
    else
     {
        for (int i = left; i <= right; i++)
	 {
            swap((str + left), (str + i));  // Swap current character
            permute(str, left + 1, right);  // Recurse for next character
            swap((str + left), (str + i));  // Backtrack by swapping back
        }
    }
}

int main()
 {
    char str[100];
    
    // Input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);  // Get length of the string
    printf("All permutations of the string are:\n");
    
    // Call permute function with starting parameters
    permute(str, 0, n - 1);

    return 0;
}

