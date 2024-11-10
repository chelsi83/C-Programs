#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to multiply two single digits (as characters)
int multiplyDigit(char a, char b) {
    return (a - '0') * (b - '0');
}

// Function to add two strings (for handling carry during addition)
char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    int carry = 0;
    int i, j;

    // Allocate enough space for the result (one extra for carry)
    char* result = (char*)malloc((maxLen + 2) * sizeof(char));

    // Initialize the result string
    for (i = 0; i <= maxLen; i++) {
        result[i] = '0';
    }
    result[maxLen + 1] = '\0';

    i = len1 - 1;
    j = len2 - 1;
    int k = maxLen;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        // Add corresponding digits from num1 and num2 if they exist
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }

        // Update carry for next addition
        carry = sum / 10;
        result[k] = (sum % 10) + '0';  // Store the current digit
        k--;
    }

    return result;
}

// Function to multiply two numbers represented as strings
char* multiplyStrings(char* num1, char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) return "0";

    // Allocate memory for the product (maximum possible length)
    int* product = (int*)calloc(len1 + len2, sizeof(int));

    // Positions in the product array
    int i, j;

    // Multiply each digit and store the result in product array
    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int mul = multiplyDigit(num1[i], num2[j]);
            int sum = mul + product[i + j + 1];

            // Store sum at the correct position
            product[i + j + 1] = sum % 10;    // Current digit
            product[i + j] += sum / 10;       // Carry to the next digit
        }
    }

    // Convert the product array to string
    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int index = 0;

    // Skip leading zeros
    while (index < len1 + len2 && product[index] == 0) {
        index++;
    }

    // If all digits are zero, return "0"
    if (index == len1 + len2) {
        result[0] = '0';
        result[1] = '\0';
    } else {
        // Convert product array to string
        int k = 0;
        while (index < len1 + len2) {
            result[k++] = product[index++] + '0';
        }
        result[k] = '\0';
    }

    // Free the allocated memory for product array
    free(product);

    return result;
}

int main() {
    char num1[100], num2[100];

    // Input the two numbers as strings
    printf("Enter first number");
    scanf("%s", num1);
    printf("Enter second number");
    scanf("%s", num2);

    // Multiply the numbers and print the result
    char* result = multiplyStrings(num1, num2);
    printf("Product: %s\n", result);

    // Free the allocated memory for the result
    free(result);

    return 0;
}

