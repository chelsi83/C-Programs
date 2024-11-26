#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    }
    Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Function to display the stack
void display(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Helper function to insert an element at the bottom of a stack
void insertAtBottom(Node** top, int data) {
    if (isEmpty(*top)) {
        push(top, data);
        return;
    }

    int temp = pop(top);
    insertAtBottom(top, data);
    push(top, temp);
}

// Function to reverse a stack
void reverseStack(Node** top) {
    if (isEmpty(*top)) {
        return;
    }

    int temp = pop(top);
    reverseStack(top);
    insertAtBottom(top, temp);
}

int main() {
    Node* stack = NULL;

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("Original stack:\n");
    display(stack);

    // Reverse the stack
    reverseStack(&stack);

    printf("Reversed stack:\n");
    display(stack);

    return 0;
}

