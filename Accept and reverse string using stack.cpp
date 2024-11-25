#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Maximum size of the stack

// Stack structure
typedef struct Stack {
    char arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push '%c'\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return '\0'; // Return null character on underflow
    }
    return s->arr[(s->top)--];
}

// Function to reverse a string using a stack
void reverseString(char *str) {
    Stack s;
    initStack(&s);

    // Push each character of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    // Pop each character from the stack and replace in the string
    int i = 0;
    while (!isEmpty(&s)) {
        str[i++] = pop(&s);
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove the newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}

