#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the array

// Stack structure
typedef struct TwoStacks {
    int arr[MAX];
    int top1; // Top of Stack 1
    int top2; // Top of Stack 2
} TwoStacks;

// Function to initialize the two stacks
void initStacks(TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = MAX;
}

// Function to check if Stack 1 is full
int isFull1(TwoStacks* ts) {
    return ts->top1 + 1 == ts->top2;
}

// Function to check if Stack 2 is full
int isFull2(TwoStacks* ts) {
    return ts->top2 - 1 == ts->top1;
}

// Function to check if Stack 1 is empty
int isEmpty1(TwoStacks* ts) {
    return ts->top1 == -1;
}

// Function to check if Stack 2 is empty
int isEmpty2(TwoStacks* ts) {
    return ts->top2 == MAX;
}

// Function to push an element onto Stack 1
void push1(TwoStacks* ts, int value) {
    if (isFull1(ts)) {
        printf("Stack 1 Overflow! Cannot push %d\n", value);
        return;
    }
    ts->arr[++(ts->top1)] = value;
    printf("Pushed %d onto Stack 1.\n", value);
}

// Function to push an element onto Stack 2
void push2(TwoStacks* ts, int value) {
    if (isFull2(ts)) {
        printf("Stack 2 Overflow! Cannot push %d\n", value);
        return;
    }
    ts->arr[--(ts->top2)] = value;
    printf("Pushed %d onto Stack 2.\n", value);
}

// Function to pop an element from Stack 1
int pop1(TwoStacks* ts) {
    if (isEmpty1(ts)) {
        printf("Stack 1 Underflow! Cannot pop.\n");
        return -1; // Return -1 to indicate underflow
    }
    return ts->arr[(ts->top1)--];
}

// Function to pop an element from Stack 2
int pop2(TwoStacks* ts) {
    if (isEmpty2(ts)) {
        printf("Stack 2 Underflow! Cannot pop.\n");
        return -1; // Return -1 to indicate underflow
    }
    return ts->arr[(ts->top2)++];
}

// Main function to demonstrate two-stack operations
int main() {
    TwoStacks ts;
    initStacks(&ts);
    int choice, stackNum, value;

    while (1) {
        printf("\nTwo Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNum);
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (stackNum == 1) {
                    push1(&ts, value);
                } else if (stackNum == 2) {
                    push2(&ts, value);
                } else {
                    printf("Invalid stack number! Please choose 1 or 2.\n");
                }
                break;
            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNum);
                if (stackNum == 1) {
                    value = pop1(&ts);
                    if (value != -1) {
                        printf("Popped value from Stack 1: %d\n", value);
                    }
                } else if (stackNum == 2) {
                    value = pop2(&ts);
                    if (value != -1) {
                        printf("Popped value from Stack 2: %d\n", value);
                    }
                } else {
                    printf("Invalid stack number! Please choose 1 or 2.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

