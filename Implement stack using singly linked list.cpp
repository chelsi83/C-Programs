#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
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

// Function to push an element onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        return -1;
    }
    Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Function to peek at the top element of the stack
int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to display the stack
void display(Node* top) {
    if (top == NULL) {
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

int main() {
    Node* stack = NULL; // Initialize an empty stack

    // Demonstrating stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack);

    printf("Top element is %d\n", peek(stack));

    printf("Popped element is %d\n", pop(&stack));
    display(stack);

    printf("Popped element is %d\n", pop(&stack));
    printf("Popped element is %d\n", pop(&stack));
    printf("Popped element is %d\n", pop(&stack)); // Trying to pop from an empty stack

    return 0;
}

