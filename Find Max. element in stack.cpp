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
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

// Function to find the maximum element in the stack
void findMaximum(Stack *stack, Stack *maxStack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Maximum element: %d\n", peek(maxStack));
}

// Main function
int main() {
    int capacity = 10;
    Stack *stack = createStack(capacity);
    Stack *maxStack = createStack(capacity); // Auxiliary stack for maximum tracking

    // Push initial elements onto the stack
    push(stack, 10);
    push(maxStack, 10); // Initialize max stack with the first element

    push(stack, 20);
    if (peek(stack) > peek(maxStack)) {
        push(maxStack, peek(stack));
    } else {
        push(maxStack, peek(maxStack));
    }

    push(stack, 15);
    if (peek(stack) > peek(maxStack)) {
        push(maxStack, peek(stack));
    } else {
        push(maxStack, peek(maxStack));
    }

    findMaximum(stack, maxStack);

    pop(stack);
    pop(maxStack);

    findMaximum(stack, maxStack);

    // Free allocated memory
    free(stack->array);
    free(stack);
    free(maxStack->array);
    free(maxStack);

    return 0;
}

