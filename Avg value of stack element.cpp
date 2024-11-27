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

// Function to calculate the average value of the stack elements
double calculateAverage(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i <= stack->top; i++) {
        sum += stack->array[i];
    }
    return (double)sum / (stack->top + 1);
}

// Main function
int main() {
    int capacity = 10;
    Stack *stack = createStack(capacity);

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    // Calculate and print the average
    double average = calculateAverage(stack);
    if (average != 0.0) {
        printf("Average value of the stack elements: %.2f\n", average);
    }

    // Free allocated memory
    free(stack->array);
    free(stack);

    return 0;
}

