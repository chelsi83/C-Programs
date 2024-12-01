#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to detect and remove a loop in the linked list
int detectAndRemoveLoop(Node* head) {
    if (!head) return 0;

    Node *slow = head, *fast = head;

    // Detect loop using Floyd's cycle detection algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected
            removeLoop(head, slow);
            return 1;
        }
    }

    return 0; // No loop detected
}

// Function to remove the loop in the linked list
void removeLoop(Node* head, Node* loopNode) {
    Node* ptr1 = head;
    Node* ptr2 = loopNode;

    // Move ptr2 to the start of the loop
    while (ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Break the loop
    ptr2->next = NULL;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeLinkedList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function for testing
int main() {
    Node* head = NULL;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    // Create a loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    // Detect and remove the loop
    if (detectAndRemoveLoop(head)) {
        printf("Loop detected and removed.\n");
    } else {
        printf("No loop detected.\n");
    }

    // Print the modified linked list
    printf("Linked List after loop removal: ");
    printList(head);

    // Free the linked list
    freeLinkedList(head);

    return 0;
}

