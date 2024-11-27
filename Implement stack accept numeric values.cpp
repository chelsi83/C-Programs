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

// Function to get the top element of the stack
int getTop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return -1 if the stack is empty
    }
    return stack->array[stack->top];
}

// Function to get the k-th element from the top of the stack
int getKthElement(Stack *stack, int k) {
    if (k <= 0 || k > stack->top + 1) {
        printf("Invalid k value\n");
        return -1; // Return -1 if k is out of range
    }
    return stack->array[stack->top - k + 1];
}

// Main function
int main() {
    int capacity = 10, k, value;
    Stack *stack = createStack(capacity);

    // Push numeric values onto the stack
    printf("Enter numbers to push onto the stack (-1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1)
            break;
        push(stack, value);
    }

    // Display the top element
    int topElement = getTop(stack);
    if (topElement != -1) {
        printf("Top element of the stack: %d\n", topElement);
    }

    // Get the k-th element from the top
    printf("Enter the value of k to find the k-th element from the top: ");
    scanf("%d", &k);
    int kthElement = getKthElement(stack, k);
    if (kthElement != -1) {
        printf("The %d-th element from the top is: %d\n", k, kthElement);
    }

    // Free allocated memory
    free(stack->array);
    free(stack);

    return 0;
}

