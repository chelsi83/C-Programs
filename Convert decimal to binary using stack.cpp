#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
typedef struct Stack {
    int *array;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return -1 if the stack is empty
    }
    return stack->array[stack->top--];
}

// Function to convert a decimal number to binary using a stack
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    int capacity = 32; // Assuming a maximum of 32 bits for the binary representation
    Stack *stack = createStack(capacity);

    // Push remainders onto the stack
    while (decimal > 0) {
        push(stack, decimal % 2);
        decimal /= 2;
    }

    // Pop and print the binary equivalent
    printf("Binary equivalent: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(stack));
    }
    printf("\n");

    // Free allocated memory
    free(stack->array);
    free(stack);
}

// Main function
int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}

