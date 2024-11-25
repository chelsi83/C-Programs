#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the stack

// Stack structure
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is Full! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty! Cannot pop.\n");
        return -1; // Return -1 to indicate underflow
    }
    return s->arr[(s->top)--];
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    initStack(&s);
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Stack is Full\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                if (isFull(&s)) {
                    printf("Stack is Full.\n");
                } else {
                    printf("Stack is not Full.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

