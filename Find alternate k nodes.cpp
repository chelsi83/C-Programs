#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse 'k' nodes in the linked list
struct Node* reverseKNodes(struct Node* head, int k) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    int count = 0;

    // Reverse first 'k' nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // After reversing, connect the rest of the list
    if (head != NULL) {
        head->next = current;
    }

    // Skip the next 'k' nodes
    count = 0;
    while (current != NULL && count < k - 1) {
        current = current->next;
        count++;
    }

    // Recursively process the remaining nodes
    if (current != NULL) {
        current->next = reverseKNodes(current->next, k);
    }

    return prev; // 'prev' is the new head after reversing
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    // Create a linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);

    int k = 3; // Number of nodes to reverse at a time
    printf("Original list:\n");
    printList(head);

    head = reverseKNodes(head, k);

    printf("Modified list after reversing alternate k nodes:\n");
    printList(head);

    return 0;
}

