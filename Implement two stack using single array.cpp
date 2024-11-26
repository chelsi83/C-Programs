#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the two stacks
typedef struct TwoStacks {
    int arr[MAX_SIZE];
    int top1; // Top of the first stack
    int top2; // Top of the second stack
} TwoStacks;

// Function to initialize the two stacks
void initialize(TwoStacks* stacks) {
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE;
}

// Function to push an element onto the first stack
void push1(TwoStacks* stacks, int data) {
    if (stacks->top1 + 1 == stacks->top2) {
        printf("Stack Overflow! Cannot push %d onto Stack 1.\n", data);
        return;
    }
    stacks->arr[++(stacks->top1)] = data;
}

// Function to push an element onto the second stack
void push2(TwoStacks* stacks, int data) {
    if (stacks->top1 + 1 == stacks->top2) {
        printf("Stack Overflow! Cannot push %d onto Stack 2.\n", data);
        return;
    }
    stacks->arr[--(stacks->top2)] = data;
}

// Function to pop an element from the first stack
int pop1(TwoStacks* stacks) {
    if (stacks->top1 == -1) {
        printf("Stack Underflow! Stack 1 is empty.\n");
        return -1;
    }
    return stacks->arr[(stacks->top1)--];
}

// Function to pop an element from the second stack
int pop2(TwoStacks* stacks) {
    if (stacks->top2 == MAX_SIZE) {
        printf("Stack Underflow! Stack 2 is empty.\n");
        return -1;
    }
    return stacks->arr[(stacks->top2)++];
}

// Function to display the elements of the first stack
void displayStack1(TwoStacks* stacks) {
    if (stacks->top1 == -1) {
        printf("Stack 1 is empty.\n");
        return;
    }
    printf("Stack 1 elements: ");
    for (int i = 0; i <= stacks->top1; i++) {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}

// Function to display the elements of the second stack
void displayStack2(TwoStacks* stacks) {
    if (stacks->top2 == MAX_SIZE) {
        printf("Stack 2 is empty.\n");
        return;
    }
    printf("Stack 2 elements: ");
    for (int i = MAX_SIZE - 1; i >= stacks->top2; i--) {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}

int main() {
    TwoStacks stacks;
    initialize(&stacks);

    // Demonstrate stack operations
    push1(&stacks, 10);
    push1(&stacks, 20);
    push1(&stacks, 30);

    push2(&stacks, 40);
    push2(&stacks, 50);
    push2(&stacks, 60);

    printf("After pushing elements:\n");
    displayStack1(&stacks);
    displayStack2(&stacks);

    printf("Popped from Stack 1: %d\n", pop1(&stacks));
    printf("Popped from Stack 2: %d\n", pop2(&stacks));

    printf("After popping elements:\n");
    displayStack1(&stacks);
    displayStack2(&stacks);

    return 0;
}

