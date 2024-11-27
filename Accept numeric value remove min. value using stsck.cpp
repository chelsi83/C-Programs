#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Function to get the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

// Function to remove the minimum value from the stack
void removeMinimum(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, nothing to remove.\n");
        return;
    }

    // Find the minimum value in the stack
    int min = INT_MAX;
    Stack *tempStack = createStack(stack->capacity);
    
    while (!isEmpty(stack)) {
        int value = pop(stack);
        if (value < min) {
            min = value;
        }
        push(tempStack, value);
    }

    // Rebuild the stack without the minimum value
    int removed = 0;
    while (!isEmpty(tempStack)) {
        int value = pop(tempStack);
        if (value != min || removed) {
            push(stack, value);
        } else {
            removed = 1; // Skip the first occurrence of the minimum
        }
    }

    printf("Removed minimum value: %d\n", min);

    // Free memory used for the temporary stack
    free(tempStack->array);
    free(tempStack);
}

// Function to display the stack
void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int capacity = 10, value;
    Stack *stack = createStack(capacity);

    printf("Enter numbers to push onto the stack (-1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        push(stack, value);
    }

    printf("\nInitial ");
    displayStack(stack);

    removeMinimum(stack);

    printf("\nAfter removing the minimum ");
    displayStack(stack);

    // Free allocated memory
    free(stack->array);
    free(stack);

    return 0;
}

