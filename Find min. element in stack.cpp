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
        return INT_MAX;
    }
    return stack->array[stack->top--];
}

// Function to get the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MAX;
    }
    return stack->array[stack->top];
}

// Function to find the minimum element in the stack
void findMinimum(Stack *stack, Stack *minStack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Minimum element: %d\n", peek(minStack));
}

// Main function
int main() {
    int capacity = 10;
    Stack *stack = createStack(capacity);
    Stack *minStack = createStack(capacity); // Auxiliary stack for minimum tracking

    push(stack, 10);
    push(minStack, 10); // Initialize minimum stack

    push(stack, 20);
    if (peek(stack) < peek(minStack)) {
        push(minStack, peek(stack));
    } else {
        push(minStack, peek(minStack));
    }

    push(stack, 5);
    if (peek(stack) < peek(minStack)) {
        push(minStack, peek(stack));
    } else {
        push(minStack, peek(minStack));
    }

    findMinimum(stack, minStack);

    pop(stack);
    pop(minStack);

    findMinimum(stack, minStack);

    // Free allocated memory
    free(stack->array);
    free(stack);
    free(minStack->array);
    free(minStack);

    return 0;
}

