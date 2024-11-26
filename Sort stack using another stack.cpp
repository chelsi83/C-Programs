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
        printf("Stack underflow!\n");
        exit(1);
    }
    Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Function to peek at the top element of the stack
int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
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

// Function to sort a stack using another stack
void sortStack(Node** originalStack) {
    Node* tempStack = NULL;

    while (!isEmpty(*originalStack)) {
        int temp = pop(originalStack);

        // Transfer elements from tempStack back to originalStack until we find the correct position
        while (!isEmpty(tempStack) && peek(tempStack) > temp) {
            push(originalStack, pop(&tempStack));
        }

        // Push the element into the correct position in tempStack
        push(&tempStack, temp);
    }

    // Transfer sorted elements back to the original stack
    while (!isEmpty(tempStack)) {
        push(originalStack, pop(&tempStack));
    }
}

int main() {
    Node* stack = NULL;

    // Push some elements onto the stack
    push(&stack, 30);
    push(&stack, 10);
    push(&stack, 50);
    push(&stack, 20);
    push(&stack, 40);

    printf("Original stack:\n");
    display(stack);

    // Sort the stack
    sortStack(&stack);

    printf("Sorted stack:\n");
    display(stack);

    return 0;
}

